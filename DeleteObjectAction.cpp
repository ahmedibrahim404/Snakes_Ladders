#include "DeleteObjectAction.h"

#include "Grid.h"
#include "Card.h"

DeleteObjectAction::DeleteObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteObjectAction::~DeleteObjectAction()
{
}

void DeleteObjectAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please click on the object you want to delete ...");
	ObjectPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void DeleteObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();
	
	pGrid->RemoveObjectFromCell(ObjectPosition);
}

