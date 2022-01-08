#pragma once

#include "action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include <fstream>

class SaveGridAction : public Action
{
	// [Actions Parameters]
	string Fname;			// The name of the saved file
public:

	SaveGridAction(ApplicationManager* pApp);

	void ReadActionParameters();
	void Execute();

	~SaveGridAction();
};

