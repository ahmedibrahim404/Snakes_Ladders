#pragma once

#include "Card.h"

class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* GetCopy(CellPosition&);

	virtual ~CardSeven(); // A Virtual Destructor
};

