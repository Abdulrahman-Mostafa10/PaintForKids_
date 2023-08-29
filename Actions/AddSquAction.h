#pragma once
#include "Action.h"
class ApplicationManager;

class AddSquAction :public Action
{
private:
	Point center;
	GfxInfo SquGfxInfo;

public:
	AddSquAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute() ;
};