

#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"
#include "Special1State.h"
#include "Special2State.h"


void Special1State::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_Special1);
	framesCounter = 0;
}

void Special1State::updateState(GameCharacter* character) {
	framesCounter++;

	if (framesCounter > 9) {
		if (IsKeyPressed(KEY_LEFT)) {

			character->isStop(false);
			character->setState(WalkForwardState::getInstance());

		}
		else if (IsKeyPressed(KEY_RIGHT)) {

			character->isStop(false);
			character->setState(WalkBackwardState::getInstance());

		}
		else if (IsKeyPressed(KEY_SPACE) && character->getStop() == false) {

			character->isStop(false);
			character->setState(JumpUpState::getInstance());
			character->isStop(true);
		}
		else if (IsKeyPressed(KEY_DOWN)) {

			character->isStop(false);
			character->setState(CrouchState::getInstance());
			character->isStop(true);
		}
		else if (IsKeyPressed(KEY_T)) {

			character->isStop(false);
			character->setState(Special2State::getInstance());
			character->isStop(true);
		}
		else {
			character->isStop(false);
			character->setState(IdleState::getInstance());

		}
	}
}


CharacterState& Special1State::getInstance() {

	static Special1State singleton;

	return singleton;

}