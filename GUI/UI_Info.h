#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR,
	MODE_FIGURES
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SHAPES,
	ITM_SELECTONE,
	ITM_CHANGEFILLCOLOR,
	ITM_CHANGEBOARDERCOLOR,
	ITM_DELETEFIG,
	ITM_MOVE,
	ITM_UNDO,
	ITM_REDO,
	ITM_CLAERALL,
	ITM_STARTREC,
	ITM_STOPREC,
	ITM_PLAYREC,
	ITM_SAVEGRAPH,
	ITM_LOADGRAPH,
	ITM_SWITCHTOPLAYMODE,
	ITM_SOUNDON,
	ITM_MUTE,
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum DrawMenuItemOfShapes
{
	RECTANGLE,
	SQUARE,
	TRIANGLE,
	HEXAGON,
	CIRCLE,
	TO_PREVIOUS,
	ITM_SHAPES_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_ByFIGURE,
	ITM_ByColor,
	ITM_Both,
	ITM_SwitchMode,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum MenuItemColors
{
	ITM_Black,
	ITM_Yellow,
	ITM_Orange,
	ITM_Red,
	ITM_Green,
	ITM_Blue,
	ITM_BACK,
	COLORS_ITM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif