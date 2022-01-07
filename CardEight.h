#pragma once

#include "Card.h"

class CardEight : public Card
{
	int coinsToPay;

public:
	CardEight(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* GetCopy(CellPosition&);

	virtual ~CardEight(); // A Virtual Destructor
};

