#include "OpenGridAction.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// Get the file name
	pOut->PrintMessage("Enter the Grid file name: ");
	this->FileName = pIn->GetSrting(pOut) + ".txt";
}

void OpenGridAction::Execute()
{
	ifstream InFile;
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	this->ReadActionParameters();
	InFile.open(FileName);

	// Check if there is a file with the entered name
	if (!InFile.is_open())
	{
		pOut->PrintMessage(FileName + "is not found!");
		return;
	}

	// Clear Grid before loading the grid
	pGrid->ClearGrid();

	// Load the Grid
	pGrid->LoadAll(InFile, pGrid);

	// Close the file
	InFile.close();

	pOut->PrintMessage("The Grid from file  " + FileName + " is Loaded Successfully");
}

OpenGridAction::~OpenGridAction(void)
{
}

