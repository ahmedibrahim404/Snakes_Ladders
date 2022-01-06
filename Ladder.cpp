#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

bool Ladder::IsOverlapping(GameObject* newObj) {
	Ladder* l = dynamic_cast<Ladder*>(newObj);
	if (l == nullptr) return false;
	return !(position.VCell() < l->GetEndPosition().VCell() || l->GetPosition().VCell() < endCellPos.VCell());
}

Ladder::~Ladder()
{
}
