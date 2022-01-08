#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	int lastRolled = pPlayer->getPlayerJustRolledNumber();
	for (int i = 0; i < lastRolled; i++) pGrid->RollCurrentPlayer();

}

void CardFive::Save(ofstream &OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardFive::Load(ifstream &Infile, Grid *pGrid)
{
	pGrid->AddObjectToCell(this);
}

