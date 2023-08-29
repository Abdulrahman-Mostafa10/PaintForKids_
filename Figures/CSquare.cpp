#include "CSquare.h"

CSquare::CSquare(Point c, GfxInfo SquareGfxInfo):CFigure(SquareGfxInfo)
{
	center = c;
}

 void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSq(center, FigGfxInfo, Selected);
}
