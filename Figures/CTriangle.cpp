#include "CTriangle.h"

CTriangle::CTriangle(Point c1, Point c2, Point c3, GfxInfo FigureGfxInfo):CFigure(FigGfxInfo)
{
	corner1 = c1;
	corner2 = c2;
	corner3 = c3;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(corner1, corner2, corner3, FigGfxInfo, Selected);
}
