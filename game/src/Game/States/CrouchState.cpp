
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"


void CrouchState::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_Crouch);

}


void CrouchState::updateState(GameCharacter* character) {

	if (!IsKeyDown(KEY_DOWN)) {

		character->setState(IdleState::getInstance());
		character->isStop(false);

	}else if (IsKeyPressed(KEY_SPACE) && character->getStop() == false) {

		character->setState(JumpUpState::getInstance());
		character->isStop(true);
	}
	/*else if (IsKeyPressed(KEY_LEFT)) {

		character->setState(WalkForwardState::getInstance());

	}else if (IsKeyPressed(KEY_RIGHT)) {

		character->setState(WalkBackwardState::getInstance());
	}*/

	// Add more states

}


CharacterState& CrouchState::getInstance() {

	static CrouchState singleton;

	return singleton;

}