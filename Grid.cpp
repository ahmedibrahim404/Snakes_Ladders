#include "Grid.h"
#include <iostream>
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Player.h"
#include "Card.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;

}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		if (IsOverlapping(pNewObject)) return false;

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}

bool Grid::IsOverlapping(GameObject* p) {
	int hCell = p->GetPosition().HCell();
	for (int i = 0; i < NumVerticalCells; i++) {
		GameObject* curCell = CellList[i][hCell]->GetGameObject();
		if (p->IsOverlapping(curCell))
			return true;
	}
	return false;
}


// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

void Grid::RollCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber - 1 + MaxPlayerCount) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

void Grid::setCurrentPlayer(int player) {
	currPlayerNumber = player;
}

void Grid::PreventNextTime(Player* currentPlayer) {
	currentPlayer->preventNextTime();
}

int Grid::GetLaddersCount()
{
	return Ladder::getLaddersCount();
}
int Grid::GetSnakesCount()
{
	return Snake::getSnakesCount();
}
int Grid::GetCardsCount()
{
	return Card::getCardsCount();
}

Card* Grid::GetCard(CellPosition& Pos)
{
	if (!Pos.IsValidCell()) {
		return NULL;
	}
	return CellList[Pos.VCell()][Pos.HCell()]->HasCard();
}

// ========= Other Getters =========


Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			Ladder* nextLadder = CellList[i][j]->HasLadder();
			if (nextLadder != NULL) {
				return nextLadder;
			}

			///TODO: Check if CellList[i][j] has a ladder, if yes return it


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Player* Grid::GetNextPlayer(const CellPosition& position)
{

	int startH = position.HCell();
	for (int i = position.VCell(); i >= 0; i--)
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			for (int k = 0; k < MaxPlayerCount; k++) {

				CellPosition currentPlayerCell = PlayerList[k]->GetCell()->GetCellPosition();
				if (currentPlayerCell.HCell() == j && currentPlayerCell.VCell() == i) return PlayerList[k];

			}



		}
		startH = 0;
	}
	return NULL;
}

Player* Grid::GetPoorestPlayer() {

	Player* poorest = PlayerList[0];
	for (int i = 0; i < MaxPlayerCount; i++) {
		if (poorest->GetWallet() > PlayerList[i]->GetWallet()) {
			poorest = PlayerList[i];
		}
	}

	return poorest;

}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

// ========= Save Grid ============

void Grid::SaveAll(ofstream& OutFile, ObjectType type)
{
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (type == ObjectType::TypeLadder)
			{
				if (CellList[i][j]->HasLadder())
				{
					CellList[i][j]->GetGameObject()->Save(OutFile);
				}
			}
			else if (type == ObjectType::TypeSnake)
			{
				if (CellList[i][j]->HasSnake())
				{
					CellList[i][j]->GetGameObject()->Save(OutFile);
				}
			}
			else if (type == ObjectType::TypeCard)
			{
				if (CellList[i][j]->HasCard())
				{
					CellList[i][j]->GetGameObject()->Save(OutFile);
				}
			}
		}
	}
}

void Grid::LoadAll(ifstream& InFile, Grid* pGrid)
{
	int LaddersNum, SnakesNum, CardsNum, CardType, CellNum;
	CellPosition C;

	Ladder* pLadder;
	Snake* pSnake;
	Card* pCard;

	InFile >> LaddersNum;
	std::cout << LaddersNum << std::endl;
	while (LaddersNum--)
	{
		int sCell, eCell;
		InFile >> sCell >> eCell;
	std:cout << sCell << " AND " << eCell << std::endl;
		pLadder = new Ladder(CellPosition::GetCellPositionFromNum(sCell), CellPosition::GetCellNumFromPosition(eCell));
		pLadder->Load(InFile, pGrid);
	}

	InFile >> SnakesNum;
	while (SnakesNum--)
	{
		int sCell, eCell;
		InFile >> sCell >> eCell;
		pSnake = new Snake(CellPosition::GetCellPositionFromNum(sCell), CellPosition::GetCellNumFromPosition(eCell));
		pSnake->Load(InFile, pGrid);
	}

	InFile >> CardsNum;
	while (CardsNum--)
	{
		InFile >> CardType;

		InFile >> CellNum;
		C = CellPosition::GetCellPositionFromNum(CellNum);

		switch (CardType){
		case 1:
			pCard = new CardOne(C);
			break;
		case 2:
			pCard = new CardTwo(C);
			break;
		case 3:
			pCard = new CardThree(C);
			break;
		case 4:
			pCard = new CardFour(C);
			break;
		case 5:
			pCard = new CardFive(C);
			break;
		case 6:
			pCard = new CardSix(C);
			break;
		case 7:
			pCard = new CardSeven(C);
			break;
		case 8:
			pCard = new CardEight(C);
			break;
		case 9:
			pCard = new CardNine(C);
			break;
		case 10:
			pCard = new CardTen(C);
			break;
		case 11:
			pCard = new CardEleven(C);
			break;
		case 12:
			pCard = new CardTwelve(C);
			break;
		}
		if(pCard != nullptr)
			pCard->Load(InFile, pGrid);
	}
}

void Grid::ClearGrid()
{
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->GetGameObject())
			{
				delete CellList[i][j]->GetGameObject();
				CellList[i][j]->SetGameObject(NULL);
			}
		}
	}
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}

