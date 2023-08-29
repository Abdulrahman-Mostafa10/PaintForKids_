#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 68;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color	
	UI.BkGrndColor = HONEYDEW;    //Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = LIGHTBLUE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

void Output::CreateFiguresToolBar() const
{
	GfxInfo toolinfo;
	toolinfo.FillClr = WHITE;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = UI.width;
	p2.y = UI.ToolBarHeight;

	UI.InterfaceMode = MODE_FIGURES;
	DrawRect(p1, p2, toolinfo, false);


	string MenuItemImageOfShapes[ITM_SHAPES_COUNT];
	MenuItemImageOfShapes[RECTANGLE] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImageOfShapes[SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImageOfShapes[TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImageOfShapes[HEXAGON] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImageOfShapes[CIRCLE] = "images\\MenuItems\\hula-hoop.jpg";
	MenuItemImageOfShapes[TO_PREVIOUS] = "images\\MenuItems\\back.jpg";
	for (int i = 0; i < ITM_SHAPES_COUNT; i++)
		pWind->DrawImage(MenuItemImageOfShapes[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	///
	///
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, 0, UI.width, 0);
}

void Output::CreateColorToolBar() const
{
	GfxInfo colorinfo;
	colorinfo.FillClr = WHITE;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = UI.width;
	p2.y = UI.ToolBarHeight;

	UI.InterfaceMode = MODE_COLOR;
	DrawRect(p1, p2, colorinfo, false); // draw a rectangle to clear toolbar

	string MenuItemColors[COLORS_ITM_COUNT];
	MenuItemColors[ITM_Black] = "images\\MenuItems\\black.jpg";
	MenuItemColors[ITM_Yellow] = "images\\MenuItems\\yellow.jpg";
	MenuItemColors[ITM_Orange] = "images\\MenuItems\\orange.jpg";
	MenuItemColors[ITM_Red] = "images\\MenuItems\\red.jpg";
	MenuItemColors[ITM_Green] = "images\\MenuItems\\green.jpg";
	MenuItemColors[ITM_Blue] = "images\\MenuItems\\blue.jpg";
	MenuItemColors[ITM_BACK] = "images\\MenuItems\\back.jpg";
	for (int i = 0; i < COLORS_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemColors[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	///
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, 0, UI.width, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SHAPES] = "images\\MenuItems\\shapes (1).jpg";
	MenuItemImages[ITM_SELECTONE] = "images\\MenuItems\\click.jpg";
	MenuItemImages[ITM_CHANGEFILLCOLOR] = "images\\MenuItems\\color-palette.jpg";
	MenuItemImages[ITM_CHANGEBOARDERCOLOR] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_DELETEFIG] = "images\\MenuItems\\trash.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLAERALL] = "images\\MenuItems\\broom.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\stop-button.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\download (1).jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\upload.jpg";
	MenuItemImages[ITM_SWITCHTOPLAYMODE] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_SOUNDON] = "images\\MenuItems\\sound-on.jpg";
	MenuItemImages[ITM_MUTE] = "images\\MenuItems\\silent 3.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);



}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;
	GfxInfo colorinfo;
	colorinfo.FillClr = WHITE;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = UI.width;
	p2.y = UI.ToolBarHeight;


	DrawRect(p1, p2, colorinfo, false); // draw a rectangle to clear toolbar
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string ToolBarImages[PLAY_ITM_COUNT];
	ToolBarImages[ITM_ByFIGURE] = "images\\MenuItems\\geometric-shape.jpg";
	ToolBarImages[ITM_ByColor] = "images\\MenuItems\\color.jpg";
	ToolBarImages[ITM_Both] = "images\\MenuItems\\figures.jpg";
	ToolBarImages[ITM_SwitchMode] = "images\\MenuItems\\switch.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(ToolBarImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, 0, UI.width, 0);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	// we noticed deecrease in thickness of red line under tool bar, So, We redraw line after each clearing for toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

bool Output::checkrect(Point p1, Point p2)const
{
	if (p1.y < UI.ToolBarHeight || p2.y < UI.ToolBarHeight || p1.y> UI.StatusBarHeight || p2.y>UI.StatusBarHeight)
		return true;
	return false;

}

bool Output::checktri(Point p1, Point p2, Point p3)const
{
	if (p1.y < UI.ToolBarHeight || p2.y < UI.ToolBarHeight || p1.y> UI.StatusBarHeight || p2.y>UI.StatusBarHeight || p3.y > UI.StatusBarHeight || p3.y < UI.ToolBarHeight)
		return true;
	return false;
}

bool Output::checksqu(Point center)const
{
	if (center.y < UI.ToolBarHeight || center.y < UI.StatusBarHeight)
		return true;
	return false;
}


bool Output::checkhex(Point pp, int length_hex) const
{
	int len = sqrt(3) * length_hex / 2;
	if (len > pp.y) // if circle is drawn over status bar
	{
		return true;
	}
	else
		return false;
}
////////////////////////////////////////////////////////////////////////////////
bool Output::checkcircle(Point pp, Point pp2) const
{
	int rad = sqrt(pow(pp.x - pp2.x, 2) + pow(pp.y - pp2.y, 2));
	if (rad > pp.y || rad > UI.height - (UI.StatusBarHeight + UI.ToolBarHeight)) // if circle is drawn over status bar
	{
		return true;
	}
	else
		return false;
}

void Output::DrawCirc(Point p1, Point p2, GfxInfo circGfxInfo, bool selected) const
{
	int radius = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	color Drawing_clr;
	if (selected)
		Drawing_clr = UI.HighlightColor;
	else
		Drawing_clr = circGfxInfo.DrawClr;

	pWind->SetPen(Drawing_clr, 1);
	drawstyle style_circ;
	if (circGfxInfo.isFilled)
	{
		style_circ = FILLED;
		pWind->SetBrush(circGfxInfo.FillClr);
	}
	else
		style_circ = FRAME;

	pWind->DrawCircle(p1.x, p1.y, radius, style_circ);
}

void Output::DrawHex(Point P_1, GfxInfo hexainfo, bool selected) const
{
	int length = 40;
	int n = P_1.x;
	int n2 = P_1.y;
	int array_x[6] =
	{
		n + length / 2,
		n + length,
		n + length / 2,
		n - length / 2,
		n - length,
		n - length / 2
	};
	int array_y[6] =
	{
		n2 + (length / 2) * sqrt(3),
		n2,
		n2 - (length / 2) * sqrt(3),
		n2 - (length / 2) * sqrt(3),
		n2,
		n2 + (length / 2) * sqrt(3),
	};
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = hexainfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (hexainfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(hexainfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(array_x, array_y, 6, style);
}

void Output::DrawSq(Point center, GfxInfo SquareGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point corner1, corner2;
	corner1.x = center.x - 50;
	corner1.y = center.y - 50;
	corner2.x = center.x + 50;
	corner2.y = center.y + 50;

	pWind->DrawRectangle(corner1.x, corner1.y, corner2.x, corner2.y, style);
}

void Output::DrawTri(Point Vertex1, Point Vertex2, Point Vertex3, GfxInfo TriGfxInfo, bool selected)const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;                               //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y, style);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

