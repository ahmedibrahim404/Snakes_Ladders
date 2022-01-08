#include "NewGameAction.h"

#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"


NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}

void NewGameAction::ReadActionParameters()
{

}


void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	CellPosition c1(1);       
	Player* currentPlayer;

	for (int i = 0; i < MaxPlayerCount; i++)
	{
		pGrid->setCurrentPlayer(i);
		currentPlayer = pGrid->GetCurrentPlayer();
		currentPlayer->ResetAll();
		pGrid->UpdatePlayerCell(currentPlayer, c1);              
	}

	pGrid->setCurrentPlayer(0);

	pGrid->SetEndGame(false);                   	  

	CardNine::setOwner(NULL);
	CardTen::setOwner(NULL);
	CardEleven::setOwner(NULL);                          

	pOut->PrintMessage("Start a new game!");
}


NewGameAction::~NewGameAction()
{

}
