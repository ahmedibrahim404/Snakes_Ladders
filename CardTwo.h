#pragma once

#include "Card.h"

class CardTwo : public Card
{

public:
	CardTwo();
	CardTwo(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Save(ofstream &OutFile);
	void Load(ifstream &Infile, Grid *pGrid);

	virtual ~CardTwo(); // A Virtual Destructor
};

