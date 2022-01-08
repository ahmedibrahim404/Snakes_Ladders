#pragma once
#include "Action.h"
#include "GameObject.h"
class DeleteObjectAction : public Action
{
	CellPosition ObjectPosition;
	GameObject* pObj;

public:

	DeleteObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (startPos, endPos)

	virtual void Execute(); // Excutes the copy process.


	virtual ~DeleteObjectAction(); // Virtual Destructor
};

