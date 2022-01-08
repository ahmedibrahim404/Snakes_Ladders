#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	CellPosition currentCellPlayer = pPlayer->GetCell()->GetCellPosition();
	Player* nextPlayer = pGrid->GetNextPlayer(currentCellPlayer);
	
	if (nextPlayer == NULL) return;
	pGrid->UpdatePlayerCell(pPlayer, CellPosition(1));

}

Card* CardSeven::GetCopy(CellPosition& Pos)
{
	return new CardSeven(Pos);
}

void CardSeven::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardSeven::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

