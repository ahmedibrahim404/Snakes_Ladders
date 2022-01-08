#include "AddLadderAction.h"
#include <windows.h> // for delay function

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter

	pOut->PrintMessage("New Ladder: Click on ladder Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter

	pOut->PrintMessage("New Ladder: Click on ladder End Cell ...");
	endPos = pIn->GetCellClicked();
	
}


// Execute the action

void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if ( startPos.HCell() != endPos.HCell() )		// Check if the ladder is not vertical
	{
		pOut->PrintMessage("Error: The Ladder must be vertical, Try again ...");
		return;
	}
	else if ( startPos.VCell() <= endPos.VCell() )	// Check if the start cell of the ladder below its end cell
	{
		pOut->PrintMessage("Error: End Cell must be above start Cell, Try again ...");
		return;
	}
	else											// Else Clear the status bar
	{
		pOut->ClearStatusBar();
	}

	// Create a Ladder object with the parameters read from the user

	Ladder * pLadder = new Ladder(startPos, endPos);

	// Add the card object to the GameObject of its Cell:
	
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	
	if ( !added )
	{
		// Print an appropriate message

		pGrid->PrintErrorMessage("Error: Cell already has an object! Click to continue ...");
	}

	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}

