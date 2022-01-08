#include "CardTwo.h"
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	// get cellposition of the player
	CellPosition currentCellPosition = pPlayer->GetCell()->GetCellPosition();

	// get next ladder after the position
	Ladder* nextLadder = pGrid->GetNextLadder(currentCellPosition);

	// if exist
	if (nextLadder != NULL) {
		// move player the end of it (or to start and take it)
		pGrid->UpdatePlayerCell(pPlayer, nextLadder->GetEndPosition());
		// if the is any (Card, Ladder, Snake) take it
		if (pPlayer->GetCell()->GetGameObject()) {
			pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
		}
	}



}

Card* CardTwo::GetCopy(CellPosition& Pos)
{
	return new CardTwo(Pos);
}

void CardTwo::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardTwo::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

