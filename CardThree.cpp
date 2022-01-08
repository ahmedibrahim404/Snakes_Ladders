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
	
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": You will play again");

	pGrid->RollCurrentPlayer();


}

Card* CardThree::GetCopy(CellPosition& Pos)
{
	return new CardThree(Pos);
}

void CardThree::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardThree::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}


