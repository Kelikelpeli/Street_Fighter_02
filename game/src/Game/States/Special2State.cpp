

#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"
#include "Special1State.h"
#include "Special2State.h"


void Special2State::enter(GameCharacter* character) {
	character->SetCharSpriteState(CharSpriteDirection::State_Special2);
	framesCounter = 0;
}

void Special2State::updateState(GameCharacter* character) {
	framesCounter ++;
	character->setAttack(false);

	if (framesCounter > 24) {
		
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
		else if (IsKeyPressed(KEY_Q)) {
			character->isStop(false);
			character->setAttack(true);

			character->setState(Special1State::getInstance());
			character->isStop(true);
		}
		else {
			character->isStop(false);
			character->setState(IdleState::getInstance());

		}
	}

}


CharacterState& Special2State::getInstance() {

	static Special2State singleton;

	return singleton;

}