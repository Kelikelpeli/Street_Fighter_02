
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"


void CrouchState::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_Crouch);
	character->setSpeed(1, 1);

}


void CrouchState::updateState(GameCharacter* character) {

	if (!IsKeyDown(KEY_DOWN)) {

		character->setState(IdleState::getInstance());
		character->isCrouch(false);

	}else if (IsKeyPressed(KEY_SPACE) && character->getJump() == false) {

		character->setState(JumpUpState::getInstance());
		character->isJump(true);
	}
	else if (IsKeyPressed(KEY_LEFT)) {

		character->setState(WalkForwardState::getInstance());

	}else if (IsKeyPressed(KEY_RIGHT)) {

		character->setState(WalkBackwardState::getInstance());
	}

	// Add more states

}


CharacterState& CrouchState::getInstance() {

	static CrouchState singleton;

	return singleton;

}