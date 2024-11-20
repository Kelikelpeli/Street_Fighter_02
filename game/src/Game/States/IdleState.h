#pragma once


#include "CharacterState.h"


class Character;


class IdleState : public CharacterState

{

public:

	void enter(GameCharacter* character) override;
	void updateState(GameCharacter* character) override;
	void exit(GameCharacter* character) override {}

	static CharacterState& getInstance();


private:

	IdleState() {}

	IdleState(const IdleState& other);

	IdleState& operator=(const IdleState& other);

};;