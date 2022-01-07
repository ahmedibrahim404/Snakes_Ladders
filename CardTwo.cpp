#include "CardTwo.h"
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	CellPosition currentCellPosition = pPlayer->GetCell()->GetCellPosition();
	Ladder* nextLadder = pGrid->GetNextLadder(currentCellPosition);

	pGrid->UpdatePlayerCell(pPlayer, nextLadder->GetEndPosition());


}

Card* CardTwo::GetCopy(CellPosition& Pos)
{
	return new CardTwo(Pos);
}