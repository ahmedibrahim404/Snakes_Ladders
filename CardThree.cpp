#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	
	pGrid->RollCurrentPlayer();

	/*
	//Alternative:
	for(int i=0;i<MaxPlayerCount-1;i++) pGrid->AdvanceCurrentPlayer();
	*/

}
