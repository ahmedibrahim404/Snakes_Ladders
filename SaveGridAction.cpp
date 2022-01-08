#include "SaveGridAction.h"


SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Get the name of the file to be saved
	pOut->PrintMessage("Please, Enter the File Name: ");
	this->Fname = pIn->GetSrting(pOut) + ".txt";
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	this->ReadActionParameters();

	// Create a file with entered name
	ofstream fout(this->Fname);

	if (fout.is_open())
	{
		// Save ladders
		fout << pGrid->GetLaddersCount() << "\n";
		pGrid->SaveAll(fout, TypeLadder);

		// Save Snakes
		fout << pGrid->GetSnakesCount() << "\n";
		pGrid->SaveAll(fout, TypeSnake);

		// Save Cards
		fout << pGrid->GetCardsCount() << "\n";
		pGrid->SaveAll(fout, TypeCard);

		// Close the file
		fout.close();
	}

	pOut->PrintMessage("Grid is Saved to " + Fname + " Successfully!");
}

SaveGridAction::~SaveGridAction()
{

}

