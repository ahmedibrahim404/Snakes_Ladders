#pragma once

#include "Card.h"
#include "Player.h"
class CardNine : public Card
{
	static int cardPrice;
	static int feesToPay;
	static Player* owner;
public:
	CardNine(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	static Player* getOwner();
	static int getPrice();
	static int getFeesToPay();

	static void setOwner(Player *);

	virtual ~CardNine(); // A Virtual Destructor
};

