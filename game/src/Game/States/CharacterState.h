#pragma once

#include "Game\Characters\Character.h"

class Character;

//////////////////////////////////////
// State Machine

class CharacterState
{
public:


	// State Mahines functions

	inline CharacterState* getCurrentState() const { return currentState; }

	// In here, we'll delegate the state transition to the currentState

	void updateState();

	// This will get called by the current state

	void setState(CharacterState& newState);


protected:





	CharacterState* currentState;
//public:
//
//
//	virtual ~CharacterState() {}
//
//	virtual void enter(GameCharacter* light) = 0;
//	virtual void updateState(GameCharacter* light) = 0;
//	virtual void exit(GameCharacter* light) = 0;
};

