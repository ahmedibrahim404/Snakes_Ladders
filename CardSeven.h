#pragma once

#include "Card.h"

class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);



	virtual ~CardSeven(); // A Virtual Destructor
};

