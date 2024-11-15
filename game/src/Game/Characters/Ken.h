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



	float GetKenJumpSpeed() { return m_KenJump_Speed; }
	float GetKenHorzontalSpeed() { return m_Ken_Horizontal_Speed; }
	float GetKenVerticalSpeed() { return m_Ken_Vertical_Speed; }

	float GetKenCurrentSpeed() { return m_Speed; }
	void  SetKenCurrentSpeed(float newSpeed) { m_Speed = newSpeed; }

	bool GetKenCanJump() { return m_bcanJump; }
	void SetKenCanJump(bool newCanJump) { m_bcanJump = newCanJump; }


private:

	const float m_KenJump_Speed = 250.f;
	const float m_Ken_Horizontal_Speed = 100.f;
	const float m_Ken_Vertical_Speed = 100.f;

	float m_Speed = {0.f};
	bool m_bcanJump = false;


};

#endif
