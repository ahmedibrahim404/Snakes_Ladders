#include "PasteCardAction.h"

#include "Grid.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please click on the cell you want to paste the card in ...");
	CardPos = pIn->GetCellClicked();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();

	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pCard = pGrid->GetClipboard();

	if (pCard == NULL)		// Check if there's a card copied or cut to be pasted
	{
		pOut->PrintMessage("Error: There is No copied or cut card! Please copy/cut a card first ... ");
	}
	else 
	{
		Card* pCopiedCard = pCard->GetCopy(CardPos);
		bool ok = pGrid->AddObjectToCell(pCopiedCard);
		if (!ok)
		{
			pOut->PrintMessage("Invalid Cell!");
		}
		else 
		{
			pCopiedCard->Draw(pOut);
			pOut->PrintMessage("Card is pasted successfully!");
		}
	}
}

