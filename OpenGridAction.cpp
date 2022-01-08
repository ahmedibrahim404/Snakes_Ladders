#include "OpenGridAction.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

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

	if (!InFile.is_open())
	{
		pOut->PrintMessage(FileName + "is not found");
		return;
	}

	pGrid->ClearGrid();

	pGrid->LoadAll(InFile, pGrid);

	InFile.close();

	pOut->PrintMessage("The Grid from file  " + FileName + " is Loaded Successfully");
}

OpenGridAction::~OpenGridAction(void)
{
}

