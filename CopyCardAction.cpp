#include "CopyCardAction.h"

#include "Grid.h"
#include "Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	// Get the CopyCard

	pOut->PrintMessage("Please click on the card you want to copy ...");
	CardPos = pIn->GetCellClicked();
}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	
	// Get a Pointer to the Input / Output Interfaces
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pCard = pGrid->GetCard(CardPos); // Make the pointer point to the card that'll be copied.
	
	if (pCard == NULL)	// If there is no card at the selected cell
	{
		pOut->PrintMessage("Invalid location!");
	}
	else 
	{
		pGrid->SetClipboard(pCard);
		pOut->PrintMessage("Card is copied successfully!");
	}
}

