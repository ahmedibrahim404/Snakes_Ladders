#pragma once

#include "Card.h"

class CardFive : public Card
{

public:
	CardFive();
	CardFive(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Save(ofstream &OutFile);
	void Load(ifstream &Infile, Grid *pGrid);

	virtual ~CardFive(); // A Virtual Destructor
};

