#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddSquAction.h"
#include"Actions\AddTriAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_FIGURE:                                                         // You are in the figure tool bar now (Mostafa)
		pOut->CreateFiguresToolBar();
		ActionType Figure_action;
		Figure_action = this->GetUserAction();

		if (Figure_action == RECTA)
		{
			pAct = new AddRectAction(this);
		}
		else if (Figure_action == SQR)
		{
			pAct = new AddSquAction(this);
		}
		else if (Figure_action == TRI)
		{
			pAct = new AddTriAction(this);
		}

	case TO_PLAY:
		pOut->CreateDrawToolBar();
		Figure_action = this->GetUserAction();
		// if(Figure_action == SELECT_BY_FIGURES)
		// pAct = new Select_By_Figure_Action(this);   // this to make an action object ( in pick and hide );
		// if(Figure_action == SELCT_BY_BOTH)
		// pAct = new Select_By_Figure_Action(this);   // this to make an action object ( in pick and hide );
		// if(Figure_action == SELECT_BY_COLOR)
		// pAct = new Select_By_Figure_Action(this);   // this to make an action object ( in pick and hide);
		break;

	case EXIT:
		///create ExitAction here


		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		//FigList[i]->PrintInfo(pOut);  // printing the info(data) for each figure 
	}

}

void ApplicationManager::Delete_Figure(CFigure* p)
{
	for (int i = 0; i < MaxFigCount; i++)
	{
		if (FigList[i] == p)
			delete FigList[i];
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
