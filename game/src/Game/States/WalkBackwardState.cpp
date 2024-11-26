
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"


void WalkBackwardState::enter(GameCharacter* character){

	character->SetCharSpriteState(CharSpriteDirection::State_WalkBackward);

}


void WalkBackwardState::updateState(GameCharacter* character){
	if (!IsKeyDown(KEY_RIGHT)) {

		character->setState(IdleState::getInstance());

	}else if (IsKeyDown(KEY_LEFT)) {

		character->setState(WalkForwardState::getInstance());
	}
	else if (IsKeyPressed(KEY_SPACE) && character->getJump() == false) {

		character->setState(JumpUpState::getInstance());
		character->isJump(true);

	}else if (IsKeyPressed(KEY_DOWN)) {

		character->setState(CrouchState::getInstance());

	}

	//…..

		// Add more states

}


CharacterState& WalkBackwardState::getInstance(){

	static WalkBackwardState singleton;

	return singleton;

}