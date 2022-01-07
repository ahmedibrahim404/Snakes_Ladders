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

	pOut->PrintMessage("please click on the cell you want to paste the card in...");
	CardPos = pIn->GetCellClicked();
}

void PasteCardAction::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pCard = pGrid->GetClipboard();

	if (pCard == NULL) {
		pOut->PrintMessage("There is no card copied or cut ! please copy or cur a card first");
	}

	else {
		Card* pCopiedCard = pCard->GetCopy(CardPos);
		bool ok = pGrid->AddObjectToCell(pCopiedCard);
		if (!ok) {
			pOut->PrintMessage("Error !! the cell must be empty and valid");
		}
		else {
			pCopiedCard->Draw(pOut);
			pOut->PrintMessage("Card is pasted successfully !!");
		}
	}
}
