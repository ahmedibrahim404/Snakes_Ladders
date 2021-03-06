#include "Player.h"

#include "GameObject.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->preventNext = 0;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::getPlayerNumber() const {
	return playerNum;
}

int Player::getPlayerJustRolledNumber() const {
	return justRolledDiceNum;
}

void Player::preventNextTime() {
	preventNext++;
}

bool Player::isPrevented() {
	return preventNext > 0;
}

void Player::decreasePreventTimes() {
	if (isPrevented()) preventNext--;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	CellPosition c = pCell->GetCellPosition();
	pOut->DrawPlayer(c, playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	CellPosition c = pCell->GetCellPosition();
	pOut->DrawPlayer(c, playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	if (isPrevented()) {
		preventNext--;
		return;
	}

	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount % 3 == 0) {
		SetWallet(GetWallet() + diceNumber * 10);
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = Player::GetCell()->GetCellPosition();
	if(pos.GetCellNum() + diceNumber > NumHorizontalCells * NumVerticalCells)
	{
		Output *pOut = pGrid->GetOutput();
		pOut->PrintMessage("Player " + to_string(this->getPlayerNumber()) + " has won!"); 
		pGrid->SetEndGame(true);
		pos = CellPosition::GetCellPositionFromNum(99);
	}
	else
	{
			pos.AddCellNum(diceNumber);
	}	
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	if(GetCell()->GetGameObject() != NULL) GetCell()->GetGameObject()->Apply(pGrid, this);
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

int Player::GetMostExpensiveStationNumber() { // return the number of the most expensive cell the player has
	
	int stationNumber = -1; // initially -1
	int stationPrice = 0; 

	if (CardNine::getOwner() == this) { // check the ownership of card 9
		if (CardNine::getPrice() > stationPrice) { // check if card 9 is the most expensive one 
			stationPrice = CardNine::getPrice();
			stationNumber = 9;
		}
	}

	if (CardTen::getOwner() == this) { // check the ownership of card 10
		if (CardTen::getPrice() > stationPrice) {  // check if card 10 is the most expensive one
			stationPrice = CardTen::getPrice();
			stationNumber = 10;
		}
	}

	if (CardEleven::getOwner() == this) { // check the ownership of card 11
		if (CardEleven::getPrice() > stationPrice) {  // check if card 11 is the most expensive one
			stationPrice = CardEleven::getPrice();
			stationNumber = 11;
		}
	}

	return stationNumber;
}


void Player::ResetAll() {
	this->wallet = 0;
	this->turnCount = 0;
}