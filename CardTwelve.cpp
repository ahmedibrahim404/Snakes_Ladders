#include "CardTwelve.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

CardTwelve::~CardTwelve(void)
{
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// get poorest player in the play
	Player* poorest = pGrid->GetPoorestPlayer();

	// get most expensive station of the current player
	int mostExpensive = pPlayer->GetMostExpensiveStationNumber();
	
	if (poorest == pPlayer) {
		pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": None will take you station, You are already the poorest player here :(");
		return;
	}

	if (mostExpensive == -1) return;// not found

	switch(mostExpensive) {
		case 9:
			CardNine::setOwner(poorest);
			break;
		case 10:
			CardTen::setOwner(poorest);
			break;
		case 11:
			CardTen::setOwner(poorest);
			break;
		default:
			break;
	}

	pOut->PrintMessage("Card " + to_string(mostExpensive) + " was transferred to player" + to_string(poorest->getPlayerNumber()));

}

Card* CardTwelve::GetCopy(CellPosition& Pos)
{
	return new CardTwelve(Pos);
}

void CardTwelve::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardTwelve::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

