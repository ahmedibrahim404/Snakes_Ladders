#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

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

Snake::~Snake()
{
}
