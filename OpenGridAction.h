#pragma once

#include "action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"

#include "Ladder.h"
#include "Snake.h"
#include "Card.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

#include <fstream>

class OpenGridAction : public Action
{
	// [Actions Parameters]
	string FileName;	// The name of the saved file
public:
	OpenGridAction(ApplicationManager* pApp);

	void ReadActionParameters();
	void Execute();

	~OpenGridAction();
};

