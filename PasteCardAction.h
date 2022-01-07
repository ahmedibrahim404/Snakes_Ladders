#pragma once
#include "Action.h"
#include "Card.h"

class PasteCardAction : public Action
{
	CellPosition CardPos;
	Card* pCard;

public:

	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~PasteCardAction(); // Virtual Destructor
};

