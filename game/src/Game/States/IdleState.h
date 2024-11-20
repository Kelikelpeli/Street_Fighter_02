#pragma once


#include "CharacterState.h"


class Character;


class IdleState : public CharacterState{
public:

	void enter(Character* character) override;
	void updateState(Character* character) override;
	void exit(Character* character) override {}
	StateType getStateType() const override { return StateType::Idle; }

	static IdleState& getInstance();


private:

	IdleState() {}

	//IdleState(const IdleState& other);

	//IdleState& operator=(const IdleState& other);

};