#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pGrid->PreventNextTime(pPlayer);

	/*
	//Alternative:
	for(int i=0;i<MaxPlayerCount-1;i++) pGrid->AdvanceCurrentPlayer();
	*/

}

Card* CardFour::GetCopy(CellPosition& Pos)
{
	return new CardFour(Pos);
}

