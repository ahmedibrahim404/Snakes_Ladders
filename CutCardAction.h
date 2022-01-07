#pragma once
#include "Action.h"

class CutCardAction : public Action
{
	CellPosition CardPos;
	Card* pCard;

public:

	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~CutCardAction(); // Virtual Destructor
};

