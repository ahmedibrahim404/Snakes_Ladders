#include "Card.h"

int Card::CardsCount = 0;			// A static member to get the created cards count

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	cellPosition = new CellPosition(pos.GetCellNum());
	CardsCount++;
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(*cellPosition, cardNumber);
}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}


bool Card::IsOverlapping(GameObject* newObj) {
	return false; // overlapping of cards will be automatically detected in Grid Class
}

int Card::getCardsCount()
{
	return CardsCount; // return the count of all cards of the grid
}

Card::~Card() // destructor
{
	CardsCount--;
}