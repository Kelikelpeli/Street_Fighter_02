
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"


void WalkForwardState::enter(GameCharacter* character){

	character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);
}


void WalkForwardState::updateState(GameCharacter* character)

{
	//	//character->setPosition(character->getPosition().x * character->getSpeed().x*1, character->getPosition().y);

	if (!IsKeyDown(KEY_LEFT)) {

		character->setState(IdleState::getInstance());

	}else if (IsKeyDown(KEY_RIGHT)) {

		character->setState(WalkBackwardState::getInstance());
	}
	else if (IsKeyPressed(KEY_SPACE) && character->getJump() == false) {

		character->setState(JumpUpState::getInstance());
		character->isJump(true);

	}else if (IsKeyPressed(KEY_DOWN)){

	    character->setState(CrouchState::getInstance());
		character->isCrouch(true);
	}
	else {
		character->setPosition(character->getPosition().x - character->getSpeed().x, character->getPosition().y);
	}
		// Add more states

}


CharacterState& WalkForwardState::getInstance()

{

	static WalkForwardState singleton;

	return singleton;

}