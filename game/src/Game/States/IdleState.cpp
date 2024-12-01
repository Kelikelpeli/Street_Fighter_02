
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"

#include "Special1State.h"
#include "Special2State.h"


void IdleState::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_Idle);
}

void IdleState::updateState(GameCharacter* character) {
	// move to walk forward state if left key is pressed
	if (IsKeyPressed(KEY_LEFT)) {

		character->setState(WalkForwardState::getInstance());

	}
	// move to walk backward state if right key is pressed
	else if (IsKeyPressed(KEY_RIGHT)) {

		character->setState(WalkBackwardState::getInstance());

	}
	// enter jump state if space is pressed
	else if (IsKeyPressed(KEY_SPACE) && character->getStop() == false) {

		character->setState(JumpUpState::getInstance());
		character->isStop(true);
	}
	// enter crouch state if down key is pressed
	else if (IsKeyPressed(KEY_DOWN)) {

		character->setState(CrouchState::getInstance());
		character->isStop(true);
	}
	//enter light attack state if Q is pressed
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
}


CharacterState& IdleState::getInstance() {

	static IdleState singleton;

	return singleton;
}