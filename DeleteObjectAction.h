#pragma once

#include "Action.h"
#include "GameObject.h"

class DeleteObjectAction : public Action
{
	// [Action Parameters]
	CellPosition ObjectPosition;	// 1- The cell position of the object
	GameObject* pObj;				// 2- The object'll be deleted

public:

	DeleteObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~DeleteObjectAction(); // Virtual Destructor
};

