#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();

	// get the last rolled player
	int lastRolled = pPlayer->getPlayerJustRolledNumber();

	// to make the player go back (lastRolled)
	// Note that if his current position is less than (lastRolled), he will be at the start of grid (Cell 1)
	int New_Cell_Num = max(1, pPlayer->GetCell()->GetCellPosition().GetCellNum() - 2 * lastRolled);	

	pOut->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": you will be back the number of dice just rolled");

	// get CellPosition of the new cell 
	CellPosition New_Cell_Position = CellPosition::GetCellPositionFromNum(New_Cell_Num);	

	// update the player position
	pGrid->UpdatePlayerCell(pPlayer, New_Cell_Position);

	// if there is any (Ladder/Snake/Card) at the new cell, take it
	if (pPlayer->GetCell()->GetGameObject()){
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);	
	}

}

Card* CardFive::GetCopy(CellPosition& Pos)
{
	return new CardFive(Pos);
}
void CardFive::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\n";
}

void CardFive::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

