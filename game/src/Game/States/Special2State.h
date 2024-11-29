#pragma once

#include "CharacterState.h"

class GameCharacter;

class Special2State : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character) {}
	static CharacterState& getInstance();

private:
	Special2State() {};
	Special2State(const Special2State& other);
	Special2State& operator=(const Special2State& other);
	float framesCounter = 0;
};