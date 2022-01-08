#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// while the selected cell is not valid, ask user to enter it
	while (moveTo.HCell() == -1 || moveTo.GetCellNum() == position.GetCellNum() ) {
		pOut->PrintMessage("New Card 6: Click the cell the player should go to ...");
		moveTo = pIn->GetCellClicked();
	}

	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	// update player cell
	pGrid->UpdatePlayerCell(pPlayer, moveTo);
	
	// if there is any (Ladder/Snake/Card) at the new cell, take it
	if (pPlayer->GetCell()->GetGameObject()){
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);	
	}

}

Card* CardSix::GetCopy(CellPosition& Pos)
{
	Card* pCard = new CardSix(Pos);
	((CardSix*)pCard)->walletAmount = walletAmount;
	((CardSix*)pCard)->moveTo = moveTo;
	return pCard;
}

void CardSix::Save(ofstream& OutFile)
{
	OutFile << this->GetCardNumber() << "\t" << this->position.GetCellNum() << "\t" << this->moveTo.GetCellNum() << "\n";
}

void CardSix::Load(ifstream& Infile, Grid* pGrid)
{
	int toCell;
	Infile >> toCell;
	moveTo = CellPosition::GetCellPositionFromNum(toCell);
	pGrid->AddObjectToCell(this);
}

