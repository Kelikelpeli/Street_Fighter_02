
#include "IdleState.h"
#include "WalkForwardState.h"
#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"


void JumpUpState::enter(GameCharacter* character){
	character->SetCharSpriteState(CharSpriteDirection::State_JumpUp);
}


void JumpUpState::updateState(GameCharacter* character){

	/*if (IsKeyPressed(KEY_LEFT)){

		character->setState(WalkForwardState::getInstance());

	}else if (IsKeyPressed(KEY_RIGHT)){

		character->setState(WalkBackwardState::getInstance());

	}*/
	if (character->getPosition().y==GetScreenHeight()/2.0f) {
		character->setState(IdleState::getInstance());
		character->isJump(false);
	}

	// Add more states

}


CharacterState& JumpUpState::getInstance(){

	static JumpUpState singleton;

	return singleton;

}