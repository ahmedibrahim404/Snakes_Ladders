#pragma once

#include "action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include <fstream>

class SaveGridAction : public Action
{
	string Fname;
public:

	SaveGridAction(ApplicationManager* pApp);

	void ReadActionParameters();
	void Execute();

	~SaveGridAction();
};

