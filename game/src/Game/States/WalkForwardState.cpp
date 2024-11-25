
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"


void WalkForwardState::enter(GameCharacter* character)

{

	character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);

}


void WalkForwardState::updateState(GameCharacter* character)

{
	if (IsKeyPressed(KEY_RIGHT)){

		character->setState(WalkBackwardState::getInstance());
		character->setPosition(character->getPosition().x * character->getSpeed().x*1, character->getPosition().y);

	} else if (IsKeyPressed(KEY_LEFT))
	{
		character->setPosition(character->getPosition().x * character->getSpeed().x*-1,character->getPosition().y);

	}
	else {
		character->setState(IdleState::getInstance());
	}

	//else

	//else if (IsKeyPressed(KEY_SPACE))

	//{

	//	character->setState(JumpState::getInstance());

	//}

	//…..

		// Add more states

}


CharacterState& WalkForwardState::getInstance()

{

	static WalkForwardState singleton;

	return singleton;

}