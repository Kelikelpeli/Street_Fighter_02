#pragma once

#include "Game/Characters/Character.h"


class Character;

//////////////////////////////////////
// State Machine
class CharacterState
{
public:
	
	//
	//virtual ~CharacterState() {}

	//virtual void enter(Character* light) = 0;
	//virtual void updateState(Character* light) = 0;
	//virtual void exit(Character* light) = 0;

	//virtual int getStateID() const = 0; // Nueva función agregada para identificar el estado actual
	//// State Mahines functions

	inline CharacterState* getCurrentState() const { return currentState; }

	// In here, we'll delegate the state transition to the currentState

	void updateState();

	// This will get called by the current state

	void setState(CharacterState& newState);


protected:





	CharacterState* currentState;
};

