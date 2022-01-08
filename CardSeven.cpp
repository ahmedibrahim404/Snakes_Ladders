#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();

	// get current player position
	CellPosition currentCellPlayer = pPlayer->GetCell()->GetCellPosition();

	// get first player after this position
	Player* nextPlayer = pGrid->GetNextPlayer(currentCellPlayer);
	
	// if no player, ignore
	if (nextPlayer == NULL) return;

	pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": First player after you i.e. Player"+ to_string(nextPlayer->getPlayerNumber()) + " will go to cell 1");
	// update position of next player to be 1
	pGrid->UpdatePlayerCell(nextPlayer, CellPosition(1));
	// if the is any (Card, Ladder, Snake) take it
	if (nextPlayer->GetCell()->GetGameObject()) {
		nextPlayer->GetCell()->GetGameObject()->Apply(pGrid, nextPlayer);
	}



}

Card* CardSeven::GetCopy(CellPosition& Pos)
{
	return new CardSeven(Pos);
}

void CardSeven::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardSeven::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

