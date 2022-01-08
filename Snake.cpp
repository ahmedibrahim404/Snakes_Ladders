#include "Snake.h"
#include "Ladder.h"
int Snake::SnakesCount = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	SnakesCount++;
	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}


void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a snake. Click to continue ...");

	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake::IsOverlapping(GameObject* newObj) {
	Snake* s = dynamic_cast<Snake*>(newObj);
	bool isOverlap = false;
	if (s != nullptr) {
		isOverlap |= !(position.VCell() > s->GetEndPosition().VCell() || newObj->GetPosition().VCell() > endCellPos.VCell());
	}

	Ladder* l = dynamic_cast<Ladder*>(newObj);
	if (l != nullptr) {
		isOverlap |= l->GetEndPosition().GetCellNum() == GetPosition().GetCellNum();
		isOverlap |= l->GetPosition().GetCellNum() == GetEndPosition().GetCellNum();
	}
	return isOverlap;

}


int Snake::getSnakesCount()
{
	return SnakesCount;
}

void Snake::Save(ofstream& OutFile)
{
	OutFile << this->position.GetCellNum() << "\t" << this->GetEndPosition().GetCellNum() << "\n";
}

void Snake::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}

Snake::~Snake()
{
	SnakesCount--;
}
