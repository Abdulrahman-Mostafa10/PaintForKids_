#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID++;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

                                          // to be continued
/*void CRectangle::PrintInfo(Output* pOut)
{
	Input* pIn = pOut->CreateInput();
	int x, y;
	string corner1_x = to_string(Corner1.x);
	string corner2_x = to_string(Corner2.x);
	string corner1_y = to_string(Corner1.y);
	string corner2_y = to_string(Corner2.y);

	pOut->PrintMessage("Click to show the ID");
	pIn->GetPointClicked(x, y);
	CFigure::PrintInfo(pOut);
	pOut->PrintMessage("Click to show the corner1");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Corner 1 is (1,0)");
	pOut->PrintMessage(corner1_x);
	pOut->PrintMessage(" , ");
	pOut->PrintMessage(corner1_y);
	pOut->PrintMessage(" ) ");

	pOut->PrintMessage("Corner 2 is ( ");
	pOut->PrintMessage(corner2_x);
	pOut->PrintMessage(" , ");
	pOut->PrintMessage(corner2_y);
	pOut->PrintMessage(" ) ");
}*/