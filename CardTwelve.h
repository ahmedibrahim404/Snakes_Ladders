#pragma once

#include "Card.h"
class CardTwelve : public Card
{
public:
	CardTwelve(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* GetCopy(CellPosition&);

	virtual ~CardTwelve(); // A Virtual Destructor
};

