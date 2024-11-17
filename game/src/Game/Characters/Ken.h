#ifndef Ken_CHAR_H
#define Ken_CHAR_H

#pragma once

#include <map>
#include <string>

#include "Game/Characters/Character.h"


class Ken : public Character
{
public:

	virtual void InitCharacter() override;
	virtual void UpdateCharacter(float deltaTime) override;
	void DrawCharacter() override;
	virtual void UnloadCharacter() override;

	//State Machine
	virtual void updateState();
	// This will get called by the current state
	virtual void setState(CharacterState& newState);





	bool GetKenCanJump() { return m_bcanJump; }
	void SetKenCanJump(bool newCanJump) { m_bcanJump = newCanJump; }


private:

	bool  m_bcanJump;

};

#endif
