#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"
#include <time.h> // used to in srand to generate random numbers with different seed

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceValueAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	if (pGrid->GetEndGame()) return;
	pOut->PrintMessage("Enter a value to dice (instead of being random)");

	int diceNumber = pIn->GetInteger(pOut); // from 1 to 6 --> should change seed

	if (diceNumber < 1 || diceNumber > 6) {
		srand((int)time(NULL));
		diceNumber = 1 + rand() % 6;
	}
	pOut->ClearStatusBar();

	Player* p = pGrid->GetCurrentPlayer();
	
	p->Move(pGrid, diceNumber);
	
	pGrid->AdvanceCurrentPlayer();
}

InputDiceValueAction::~InputDiceValueAction()
{
}
