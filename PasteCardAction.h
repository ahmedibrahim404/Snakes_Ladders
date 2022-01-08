#pragma once

#include "Action.h"
#include "Card.h"

class PasteCardAction : public Action
{
	// [Action Parameters]
	CellPosition CardPos;	// 1- The postion of the card
	Card* pCard;			// 2- The Paste Card

public:
	
	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~PasteCardAction(); // Virtual Destructor
};

