#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Card 8: Enter coins the player must pay to be out of jail ...");

	// Read the coins the player MUST pay
	coinsToPay = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// check if player has money enough to pay
	if (pPlayer->GetWallet() >= coinsToPay) {
		pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": You entered Jail and have to options: Write (0) to be prevented from playing 3 times anything else to pay " + to_string(coinsToPay) + "Coins");
		int chose = pIn->GetInteger(pOut);

		if (chose == 0) {
			for(int i=0;i<3;i++) pPlayer->preventNextTime();
		} else {
			pPlayer->SetWallet(pPlayer->GetWallet() - coinsToPay);
		}
	} else {
		pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ":You don't have enought coins( " + to_string(coinsToPay) + "Coins), so you will be prevented from playing 3 times");
		for (int i = 0; i < 3; i++) pPlayer->preventNextTime();
	}

}

Card* CardEight::GetCopy(CellPosition& Pos)
{
	Card* pCard = new CardEight(Pos);
	((CardEight*)pCard)->coinsToPay = coinsToPay;
	return pCard;
}

void CardEight::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\t" << this->coinsToPay << "\n";
}

void CardEight::Load(ifstream& Infile, Grid* pGrid)
{
	Infile >> coinsToPay;
	pGrid->AddObjectToCell(this);
}

