#pragma once
#include"CFigure.h"
class CTriangle : public CFigure
{
private:
	Point corner1,corner2,corner3;
public:
	CTriangle(Point,Point,Point ,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	//virtual void PrintInfo(Output* pOut);
};
