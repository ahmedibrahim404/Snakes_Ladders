#pragma once

#include "Card.h"

class CardThree : public Card
{

public:
	CardThree();
	CardThree(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Save(ofstream &OutFile);
	void Load(ifstream &Infile, Grid *pGrid);

	virtual ~CardThree(); // A Virtual Destructor
};

