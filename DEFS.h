#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{

	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action	
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	///(Done)TODO: Add more action types of Design Mode
	COPY_CARD,		// Copy the Card with all its data to the clipboard
	CUT_CARD,		// Cut the Card with all its data to the clipboard
	PASTE_CARD,		// Paste the Card in the clipboard to the destination cell
	DELETE_OBJECT,	// Delete the game object in the cell
	SAVE_GRID,		// Save the information of the designed grid
	OPEN_GRID,		// Open a saved grid from a file and re-draw it
	
	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	TO_DESIGN_MODE,	// Go to Design Mode

	///(Done)TODO: Add more action types of Play Mode
	INPUT_DICE_VALUE,	//ask a user to enter a dice value instead of generating a random value
	NEW_GAME,			//Restarts players positions, wallets, and turn returns to player 0

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

enum ObjectType
{
	TypeLadder,
	TypeSnake,
	TypeCard
};

#endif