
#include "IdleState.h"
#include "Game\Characters\Character.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "JumpUpState.h"
#include "CrouchState.h"

IdleState& IdleState::getInstance() {
	static IdleState instance;
	return instance;
}

void IdleState::enter(Character* character) {
	// Set the animation for the Idle state (each character handles its own animation)
	character->setStateAnimation(StateType::Idle);
}

void IdleState::updateState(Character* character){

	if (IsKeyPressed(KEY_LEFT)){

		character->setState(WalkForwardState::getInstance());

	}

	else if (IsKeyPressed(KEY_RIGHT)){

		character->setState(WalkBackwardState::getInstance());

	}

	else if (IsKeyPressed(KEY_UP)){

		character->setState(JumpUpState::getInstance());

	}
	else if (IsKeyPressed(KEY_DOWN)) {
		character->setState(CrouchState::getInstance());
	}


	// Add more states

}


