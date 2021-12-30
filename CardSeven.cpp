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