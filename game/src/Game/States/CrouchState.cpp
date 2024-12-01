
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"

#include "Special1State.h"
#include "Special2State.h"


void CrouchState::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_Crouch);
}

void CrouchState::updateState(GameCharacter* character) {
	if (!IsKeyDown(KEY_DOWN)) {  // while the key remains pressed, it does not change state

		character->setState(IdleState::getInstance());
		character->isStop(false);

	}
	// enter jump state if space is pressed
	else if (IsKeyPressed(KEY_SPACE) && character->getStop() == false) { 

		character->setState(JumpUpState::getInstance());
		character->isStop(true);

	}
	// enter light attack state if Q is pressed
	else if (IsKeyPressed(KEY_Q)) {
		character->setAttack(true);
		character->setState(Special1State::getInstance());
		character->isStop(true);

	}
	// enter medium attack state if T is pressed
	else if (IsKeyPressed(KEY_T)) {
		character->setAttack(true);
		character->setState(Special2State::getInstance());
		character->isStop(true);

	}
	// move to walk forward state if left key is pressed
	else if (IsKeyPressed(KEY_LEFT)) {
		character->setState(WalkForwardState::getInstance());

	}
	// move to walk backward state if right key is pressed
	else if (IsKeyPressed(KEY_RIGHT)) {
		character->setState(WalkBackwardState::getInstance());
	}
}

CharacterState& CrouchState::getInstance() {
	static CrouchState singleton;

	return singleton;
}