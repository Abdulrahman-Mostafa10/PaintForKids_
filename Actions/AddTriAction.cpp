#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddTriAction::AddTriAction(ApplicationManager* pMAN) :Action(pMAN)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("For the new Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p1.x, p1.y);

	pOut->PrintMessage("For the new Triangle: Click at second corner");
	//Read 1st corner and store in point P2
	pIn->GetPointClicked(p2.x, p2.y);

	pOut->PrintMessage("For the new Triangle: Click at third corner");
	//Read 1st corner and store in point P3
	pIn->GetPointClicked(p3.x, p3.y);

	TriGfxInfo.isFilled = false;	//default is not filled                                <---------   // 5aly balak de lazem ttzbt k logic 
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CTriangle* T = new CTriangle(p1, p2,p3, TriGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(T);
}