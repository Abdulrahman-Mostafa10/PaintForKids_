#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}
	else if (y >= UI.height - UI.StatusBarHeight)
	{
		return STATUS;
	}

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//case ITM_RECT: return DRAW_RECT;
			case ITM_SHAPES: return ADD_FIGURE;
			case ITM_SELECTONE: return SELECT_ONE;
			case ITM_CHANGEFILLCOLOR: return CHANGE_FILLCOLOR;
			case ITM_CHANGEBOARDERCOLOR: return CHANGE_BOARDERCOLOR;
			case ITM_DELETEFIG: return DELETE_FIG;
			case ITM_MOVE:return MOVE_FIG;
			case ITM_UNDO:return UNDO;
			case ITM_REDO: return REDO;
			case ITM_CLAERALL:return CLEAR;
			case ITM_STARTREC: return START_REC;
			case ITM_STOPREC: return STOP_REC;
			case ITM_PLAYREC: return PLAY_REC;
			case ITM_SAVEGRAPH:return SAVE_GRAPH;
			case ITM_LOADGRAPH: return LOAD_GRAPH;
			case ITM_SWITCHTOPLAYMODE: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

	}
	else if (UI.InterfaceMode == MODE_COLOR)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//case ITM_RECT: return DRAW_RECT;
			case ITM_Black: return BLACKCOLOR;
			case ITM_Blue:  return BLUECOLOR;
			case ITM_Green: return GREENCOLOR;
			case ITM_Orange: return ORANGECOLOR;
			case ITM_Red: return REDCOLOR;
			case ITM_Yellow: return YELLOWCOLOR;
			case ITM_BACK: return RETURNCOLOR;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
	}
	else if (UI.InterfaceMode == MODE_FIGURES)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
				//case ITM_RECT: return DRAW_RECT;
			case RECTANGLE: return RECTA;
			case CIRCLE:  return CIRC;
			case SQUARE: return SQR;
			case TRIANGLE: return TRI;
			case HEXAGON: return HEX;
			case TO_PREVIOUS: return RETURN_FIGURES;
			case ITM_BACK: return RETURNCOLOR;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
	}

	else	//GUI is in PLAY mode
	{
		///TODO:
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_ByFIGURE:return SELECT_BY_FIGURES;
		case ITM_ByColor: return SELECT_BY_COLOR;
		case ITM_Both: return SELCT_BY_BOTH;
		case ITM_SwitchMode:return TO_DRAW;
		default: return EMPTY;
		}
	}
}
/////////////////////////////////

Input::~Input()
{
}
