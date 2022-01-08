#include "CutCardAction.h"

#include "Grid.h"
#include "Card.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please click on the card you want to cut ...");
	CardPos = pIn->GetCellClicked();
}

void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	ReadActionParameters();
	
	pCard = pGrid->GetCard(CardPos); // Make the pointer point to the card that'll be cut
	
	if (pCard == NULL)				// If there is no card at the selected cell
	{
		pOut->PrintMessage("Invalid location!");
	}
	else
	{
		pGrid->SetClipboard(pCard->GetCopy(CardPos));
		pGrid->RemoveObjectFromCell(CardPos);
		pOut->PrintMessage("Card is cut succesfully!");
	}
}

