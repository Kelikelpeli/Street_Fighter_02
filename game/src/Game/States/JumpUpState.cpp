
#include "IdleState.h"
#include "WalkForwardState.h"
#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"
#include "Special1State.h"
#include "Special2State.h"

void JumpUpState::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_JumpUp);

	character->isStop(true); // Marks the character as jumping
	startTime = GetTime();   // Records the start time of the jump
}


void JumpUpState::updateState(GameCharacter* character) {
	const float jumpDuration = 2.0f;    // Total jump duration (in seconds)
	const float jumpHeight = 450.0f;   // Maximum jump height
	const float gravity = 300.0f;      // Falling speed
	float elapsedTime = GetTime() - startTime; // Time elapsed since the jump started

	// Rising phase
	if (elapsedTime < jumpDuration / 2) {
		character->setPosition(character->getPosition().x, character->getPosition().y - jumpHeight * GetFrameTime());
	}
	// Falling phase
	else if (elapsedTime < jumpDuration) {
		character->setPosition(character->getPosition().x, character->getPosition().y + gravity * GetFrameTime());
	}
	else {
		// Ends the jump
		character->setPosition(character->getPosition().x, character->groundLevel); // Adjusts the position to the ground level
		character->isStop(false);
		character->setState(IdleState::getInstance());
	}
}


CharacterState& JumpUpState::getInstance() {
	static JumpUpState singleton;

	return singleton;
}