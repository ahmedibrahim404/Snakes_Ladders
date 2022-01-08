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
	
	Output* pOut = pGrid->GetOutput();

	// prevent player from playing next time
	pPlayer->preventNextTime();
	pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": you will be prevented from playing the next turn");

}

Card* CardFour::GetCopy(CellPosition& Pos)
{
	return new CardFour(Pos);
}

void CardFour::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardFour::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

