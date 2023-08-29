#pragma once
#include "Action.h"
class ApplicationManager;

class AddTriAction :public Action
{
private:
	Point p1,p2,p3;
	GfxInfo TriGfxInfo;

public:
	AddTriAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute();
};