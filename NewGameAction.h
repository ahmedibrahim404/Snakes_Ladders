#include "Action.h"

class NewGameAction : public Action
{

public:
	NewGameAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	void Execute();          

	~NewGameAction();
};

