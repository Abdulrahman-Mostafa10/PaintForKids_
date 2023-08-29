#include "AddSquAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquAction::AddSquAction(ApplicationManager* AppMan) :Action(AppMan)
{}


void AddSquAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center");

	//Read and store in center point
	pIn->GetPointClicked(center.x, center.y);

	SquGfxInfo.isFilled = false;	//default is not filled                                <---------   // 5aly balak de lazem ttzbt k logic 
	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CSquare* S = new CSquare(center, SquGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
}
