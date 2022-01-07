#pragma once
#include "Action.h"

class CopyCardAction : public Action
{
	CellPosition CardPos;
	Card* pCard;

public:

	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~CopyCardAction(); // Virtual Destructor
};

