#ifndef Ken_CHAR_H
#define Ken_CHAR_H

#pragma once

#include <map>
#include <string>

#include "Game/Characters/Character.h"


class Ken : public GameCharacter
{
public:

	virtual void InitGameCharacter() override;
	virtual void UpdateGameCharacter(float deltaTime) override;
	virtual void DrawGameCharacter() override;
	virtual void UnloadGameCharacter() override;

	//State Machine
	virtual void updateState();
	// This will get called by the current state
	virtual void setState(CharacterState& newState);
	Rectangle getHitColliderRect();
 
	
private:

	// Special additions for this character
	Texture2D punchText;
	Rectangle hitColliderRect;
};

#endif
