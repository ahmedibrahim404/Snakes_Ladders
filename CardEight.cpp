#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{


	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Card 1: Enter its coints to pay to be out of jail ...");

	coinsToPay = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (pPlayer->GetWallet() < coinsToPay) {
		pOut->PrintMessage("You entered Jail and have to options: Write (0) to be prevented from playing 3 times anything else to pay " + to_string(coinsToPay) + "Coins");
		int chose = pIn->GetInteger(pOut);

		if (chose == 0) {
			pGrid->PreventNextTime(pPlayer);
			pGrid->PreventNextTime(pPlayer);
			pGrid->PreventNextTime(pPlayer);
		} else {
			pPlayer->SetWallet(pPlayer->GetWallet() - coinsToPay);
		}
	} else {
		pGrid->PreventNextTime(pPlayer);
		pGrid->PreventNextTime(pPlayer);
		pGrid->PreventNextTime(pPlayer);
	}

}