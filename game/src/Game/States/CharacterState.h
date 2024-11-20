#pragma once
#include "Game/Characters/Character.h"
#include"StateType.h"
class Character;

class CharacterState {
public:
    virtual ~CharacterState() {}

    // State machine functions

    virtual void enter(Character* character) = 0;
    virtual void updateState(Character* character) = 0;
    virtual void exit(Character* character) = 0;
    virtual StateType getStateType() const = 0;
protected:
  //  CharacterState* currentState; // Pointer to the current state
};
