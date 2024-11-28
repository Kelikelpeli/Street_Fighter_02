#pragma once

#include "CharacterState.h"

class GameCharacter;

class Special1State : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character) {}
	static CharacterState& getInstance();

private:
	Special1State() {};
	Special1State(const Special1State& other);
	Special1State& operator=(const Special1State& other);
};