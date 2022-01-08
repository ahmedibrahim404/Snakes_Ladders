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

	int lastRolled = pPlayer->getPlayerJustRolledNumber();


	int New_Cell_Num = max(1, pPlayer->GetCell()->GetCellPosition().GetCellNum() - 2 * lastRolled);	

	CellPosition New_Cell_Position = CellPosition::GetCellPositionFromNum(New_Cell_Num);	

	pGrid->UpdatePlayerCell(pPlayer, New_Cell_Position);

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

