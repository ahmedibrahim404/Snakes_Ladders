#include "Snake.h"
#include "Ladder.h"
int Snake::SnakesCount = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	
	// increase total number of snakes
	SnakesCount++;
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}


void Snake::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a snake. Click to continue ...");

	// move player to the end cell
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());

	// if reached any card take it
	if (pPlayer->GetCell()->GetGameObject()) {
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	}

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake::IsOverlapping(GameObject* newObj) {

	// if the object is snake
	Snake* s = dynamic_cast<Snake*>(newObj);

	bool isOverlap = false;
	// check if 2 snakes overlap each other
	if (s != nullptr) {
		isOverlap |= !(position.VCell() > s->GetEndPosition().VCell() || newObj->GetPosition().VCell() > endCellPos.VCell());
	}

	// if the object is ladder
	Ladder* l = dynamic_cast<Ladder*>(newObj);

	// if ladder and snake, check both doesn't have same start or end
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

Snake::~Snake() // destructor
{
	SnakesCount--;
}
