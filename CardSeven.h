#pragma once

#include "Card.h"

class CardSeven : public Card
{

public:
	CardSeven();
	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Save(ofstream &OutFile);
	void Load(ifstream &Infile, Grid *pGrid);

	virtual ~CardSeven(); // A Virtual Destructor
};

