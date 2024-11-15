#pragma once

#include "Game/Characters/Character.h"


class Character;

//////////////////////////////////////
// State Machine
class CharacterState
{
public:
	
	
	virtual ~CharacterState() {}

	virtual void enter(Character* light) = 0;
	virtual void updateState(Character* light) = 0;
	virtual void exit(Character* light) = 0;

	virtual int getStateID() const = 0; // Nueva función agregada para identificar el estado actual
};

