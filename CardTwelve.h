#pragma once

#include "Card.h"
class CardTwelve : public Card
{
public:
	CardTwelve(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* GetCopy(CellPosition&);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardTwelve(); // A Virtual Destructor
};

