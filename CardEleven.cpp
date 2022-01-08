#include "CardEleven.h"

Player* CardEleven::owner = nullptr;
int CardEleven::cardPrice = 0;
int CardEleven::feesToPay = 0;
int CardEleven::cardElevenCount = 0;
CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (11 here)
	cardElevenCount++;
}

CardEleven::~CardEleven(void)
{
	cardElevenCount--;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (cardElevenCount != 0) return;

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Card 10: Enter its price ...");
	CardEleven::cardPrice = pIn->GetInteger(pOut);

	pOut->PrintMessage("New Card 10: Enter fees the passing player should pay ...");
	CardEleven::feesToPay = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (owner == nullptr) { // if station is not bought

		// if player can afford for it
		if (pPlayer->GetWallet() < cardPrice) return;

		// print message to player
		pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": Do you want to buy this station for " + to_string(cardPrice) + " coins? (1 For Yes, 0 For No)");
		int chose = pIn->GetInteger(pOut);
		
		if (chose == 1) { // if option is to buy
			CardEleven::owner = pPlayer;
			pPlayer->SetWallet(pPlayer->GetWallet() - cardPrice);
		}

		pOut->ClearStatusBar();

	}
	else {

		if (pPlayer != owner) { // if the player passed is not the owner
			pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": You must PAY " + to_string(feesToPay) + " to Player " + to_string(owner->getPlayerNumber()) + " because you are in their land");
			
			// take from the player passed feesToPay coins
			// note wallet may be negative
			pPlayer->SetWallet(pPlayer->GetWallet() - feesToPay);
			
			// give to the owner the coins
			owner->SetWallet(owner->GetWallet() + feesToPay);
		} else {
			pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": Welcome to Your station, Sir");
		}

	}

}

Player* CardEleven::getOwner() {
	return CardEleven::owner;
}


int CardEleven::getPrice() {
	return CardEleven::cardPrice;
}

int CardEleven::getFeesToPay() {
	return CardEleven::feesToPay;
}

void CardEleven::setOwner(Player* newOwner) {
	CardEleven::owner = newOwner;
}

Card* CardEleven::GetCopy(CellPosition& Pos)
{
	Card* pCard = new CardEleven(Pos);
	return pCard;
}

void CardEleven::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\t" << this->cardPrice << "\t" << this->feesToPay << "\n";
}

void CardEleven::Load(ifstream& Infile, Grid* pGrid)
{
	Infile >> cardPrice >> feesToPay;
	pGrid->AddObjectToCell(this);
}

