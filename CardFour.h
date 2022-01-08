#pragma once

#include "Card.h"

class CardFour : public Card
{

public:
	CardFour(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Save(ofstream &OutFile);
	void Load(ifstream &Infile, Grid *pGrid);

	virtual ~CardFour(); // A Virtual Destructor
};

