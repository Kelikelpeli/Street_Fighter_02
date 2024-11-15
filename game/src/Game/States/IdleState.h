#pragma once

#include "BaseCharacterState.h"

class IdleState : public BaseCharacterState
{
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}
    static CharacterState& getInstance();
    int getStateID() const override;

private:
    IdleState() {}
    IdleState(const IdleState& other);
    IdleState& operator=(const IdleState& other);
};


//#pragma once
//
//#include "CharacterState.h"
//
//class GameCharacter;
//
//class IdleState : public CharacterState
//{
//public:
//	void enter(GameCharacter* character);
//	void updateState(GameCharacter* character);
//	void exit(GameCharacter* character) {}
//	static CharacterState& getInstance();
//	int getStateID() const override; 
//
//private:
//	IdleState() {}
//	IdleState(const IdleState& other);
//	IdleState& operator=(const IdleState& other);
//};