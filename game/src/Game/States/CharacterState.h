#pragma once
#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

#include "Game/Characters/Character.h"


class Character;

//////////////////////////////////////
// State Machine
class CharacterState
{
public:
	
    virtual ~CharacterState() {}

    // Enter the state
    virtual void enter(Character* character) = 0;

    // Update the state
    virtual void updateState(Character* character) = 0;

    // Exit the state
    virtual void exit(Character* character) = 0;


protected:
    //CharacterState* currentState;
};

#endif