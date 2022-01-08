#pragma once
#include "Action.h"

class CopyCardAction : public Action
{
	// [Action Parameters]
	CellPosition CardPos;	// 1- The postion of the card
	Card* pCard;			// 2- The Copy Card

public:

	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~CopyCardAction(); // Virtual Destructor
};

