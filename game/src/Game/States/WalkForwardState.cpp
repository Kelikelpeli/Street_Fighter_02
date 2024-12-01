#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"
#include "Special1State.h"
#include "Special2State.h"

void WalkForwardState::enter(GameCharacter* character) {

	character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);
}

void WalkForwardState::updateState(GameCharacter* character) {
	if (!IsKeyDown(KEY_LEFT)) { // As long as it's still pressed, it doesn't change state
		character->setState(IdleState::getInstance());
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		character->setState(WalkBackwardState::getInstance());
	}
	else if (IsKeyPressed(KEY_SPACE) && character->getStop() == false) {
		character->setState(JumpUpState::getInstance());
		character->isStop(true);
	}
	else if (IsKeyPressed(KEY_DOWN)) {
		character->setState(CrouchState::getInstance());
		character->isStop(true);
	}
	else if (IsKeyPressed(KEY_Q)) {
		character->setAttack(true);
		character->setState(Special1State::getInstance());
		character->isStop(true);
	}
	else if (IsKeyPressed(KEY_T)) {
		character->setAttack(true);
		character->setState(Special2State::getInstance());
		character->isStop(true);
	}
	else {
		character->setPosition(character->getPosition().x - character->getSpeed().x, character->getPosition().y);
	}
}


CharacterState& WalkForwardState::getInstance() {
	static WalkForwardState singleton;

	return singleton;
}