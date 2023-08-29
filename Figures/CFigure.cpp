#include "CFigure.h"


int CFigure::ID = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

//void CFigure::PrintInfo(Output* pOut)const
//{
	//	pOut->PrintMessage("ID = ");
		//pOut->PrintMessage(get_id());
//}

string CFigure::get_id()const
{
	return to_string(ID);
}


