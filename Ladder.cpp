#include "Ladder.h"

int Ladder::LaddersCount = 0;

Ladder::Ladder()
{

}

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	LaddersCount++;
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

int Ladder::getLaddersCount()
{
	return LaddersCount;
}

void Ladder::Save(ofstream &OutFile)
{
	OutFile << this->position.GetCellNum() << "\t" << this->GetEndPosition().GetCellNum() << "\n";
}

void Ladder::Load(ifstream &Infile, Grid *pGrid)
{
	int sCell, eCell;
	Infile >> sCell >> eCell;
	
	this->position = CellPosition::GetCellPositionFromNum(sCell);
	this->endCellPos = CellPosition::GetCellNumFromPosition(eCell);

	pGrid->AddObjectToCell(this);
}

Ladder::~Ladder()
{
	LaddersCount--;
}

