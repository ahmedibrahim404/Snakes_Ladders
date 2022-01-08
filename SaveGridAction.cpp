#include "SaveGridAction.h"


SaveGridAction::SaveGridAction( ApplicationManager* pApp ) : Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	pOut->PrintMessage("Please, Enter the File Name: ");
	this->Fname = pIn->GetSrting( pOut ) + ".txt";
}

void SaveGridAction::Execute()
{
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	this->ReadActionParameters();

	ofstream fout(this->Fname);

	if( fout.is_open() )
	{
		fout << pGrid->GetLaddersCount() << "\n";
		pGrid->SaveAll( fout , TypeLadder );

		fout << pGrid->GetSnakesCount() << "\n";
		pGrid->SaveAll( fout , TypeSnake );

		fout << pGrid->GetCardsCount() << "\n";
		pGrid->SaveAll( fout , TypeCard );

		fout.close();
	}
	pOut->PrintMessage( "Grid is Saved to " + Fname + " Successfully." );
}

SaveGridAction::~SaveGridAction()
{

}


