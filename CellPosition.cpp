#include "CellPosition.h"
#include "UI_Info.h"
#include <iostream>
CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	// checks if v is not out of boundary
	if (v < NumVerticalCells && v >= 0) {
		vCell = v;
		return true;
	}

	return false; 
}

bool CellPosition::SetHCell(int h) 
{
	if (h < NumHorizontalCells && h >= 0) {
		hCell = h;
		return true;
	}

	return false;
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	// checks if vCell and hCell aren't out of boundary
	return vCell < NumVerticalCells && vCell >= 0 && hCell < NumHorizontalCells && hCell >= 0;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	int v = cellPosition.VCell();
	int h = cellPosition.HCell();

	if ( v >= NumVerticalCells || v<0 || h >= NumHorizontalCells || h <0)
		return -1;

	return	(NumVerticalCells - v - 1) * NumHorizontalCells + h + 1;

}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	if (cellNum <=0 || cellNum >99)
		return position;

	int h = (cellNum-1)%NumHorizontalCells; // get hCell
	int v = NumVerticalCells-(cellNum-1)/NumHorizontalCells-1; // get vCell

	position.SetHCell(h);
	position.SetVCell(v);

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	int cellNum = GetCellNum();
	int newCellNum = cellNum + addedNum; // get new cell number
	CellPosition newCell = GetCellPositionFromNum(newCellNum); // get position of new cell
	SetHCell(newCell.HCell()); // update HCell & VCell of current Cell
	SetVCell(newCell.VCell());
}
