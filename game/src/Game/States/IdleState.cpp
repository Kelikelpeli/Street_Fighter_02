

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

	if (IsKeyPressed(KEY_LEFT)){

		character->setState(WalkForwardState::getInstance());

	} else if (IsKeyPressed(KEY_RIGHT)){

		character->setState(WalkBackwardState::getInstance());

	}else if (IsKeyPressed(KEY_SPACE) && character->getStop() == false) {

		character->setState(JumpUpState::getInstance());
		character->isStop(true);
	}
	else if (IsKeyPressed(KEY_DOWN)){

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

	// Add more states

}


CharacterState& IdleState::getInstance() {

	static IdleState singleton;

	return singleton;

}