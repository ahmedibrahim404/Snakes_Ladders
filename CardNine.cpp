#include "CardNine.h"

Player* CardNine::owner = nullptr;
int CardNine::cardPrice = 0;
int CardNine::feesToPay = 0;
int CardNine::cardNineCount = 0;

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
	cardNineCount++; // increase the total number of card nine in the grid
}

CardNine::~CardNine()
{
	cardNineCount--;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	// if first card nine in the grid, take the parameters from input, otherwise ignore
	if (CardNine::cardNineCount != 1) return; 


	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Card 9: Enter its price ...");
	CardNine::cardPrice = pIn->GetInteger(pOut);

	pOut->PrintMessage("New Card 9: Enter fees the passing player should pay ...");
	CardNine::feesToPay = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (owner == nullptr) { // if station is not bought

		if (pPlayer->GetWallet() < cardPrice) return;

		pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": Do you want to buy this station for " + to_string(cardPrice) + " coins? (1 For Yes, 0 For No)");
		int chose = pIn->GetInteger(pOut);
		if (chose == 1) {
			pPlayer->SetWallet(pPlayer->GetWallet() - cardPrice);
			CardNine::owner = pPlayer;
			pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + " now owns stations 9");
		}


	} else {

		if (pPlayer != owner) {
			pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": You must PAY " + to_string(feesToPay) + " to Player " + to_string(owner->getPlayerNumber()) + " because you are in their land");
			pPlayer->SetWallet(pPlayer->GetWallet() - feesToPay);
			owner->SetWallet(owner->GetWallet() + feesToPay);
		}
		else {
			pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": Welcome to Your station, Sir");
		}

	}

}

Player* CardNine::getOwner() {
	return CardNine::owner;
}

int CardNine::getPrice() {
	return CardNine::cardPrice;
}

int CardNine::getFeesToPay() {
	return CardNine::feesToPay;
}

void CardNine::setOwner(Player* newOwner) {
	CardNine::owner = newOwner;
}

Card* CardNine::GetCopy(CellPosition& Pos)
{
	Card* pCard = new CardNine(Pos);
	return pCard;
}

void CardNine::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\t" << this->cardPrice << "\t" << this->feesToPay << "\n";
}

void CardNine::Load(ifstream& Infile, Grid* pGrid)
{
	Infile >> cardPrice >> feesToPay;
	pGrid->AddObjectToCell(this);
}

