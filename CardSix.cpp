#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{


	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Card 6: Click the cell the player should go to ...");
	
	moveTo = pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pGrid->UpdatePlayerCell(pPlayer, moveTo);

}
