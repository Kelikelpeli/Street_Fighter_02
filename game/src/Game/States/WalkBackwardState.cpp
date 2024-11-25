
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"


void WalkBackwardState::enter(GameCharacter* character)

{

	character->SetCharSpriteState(CharSpriteDirection::State_WalkBackward);

}


void WalkBackwardState::updateState(GameCharacter* character)

{
	if (IsKeyPressed(KEY_RIGHT)) {

		//character->setState(WalkBackwardState::getInstance());
		character->setPosition(character->getPosition().x * character->getSpeed().x * 1, character->getPosition().y);

	}
	else if (IsKeyPressed(KEY_LEFT))
	{
		character->setState(WalkForwardState::getInstance());
		character->setPosition(character->getPosition().x * character->getSpeed().x * -1, character->getPosition().y);

	}
	else {
		character->setState(IdleState::getInstance());
	}

	//if (IsKeyPressed(KEY_LEFT))

	//{

	//	character->setState(WalkForwardState::getInstance());

	//}

	//else if (IsKeyPressed(KEY_RIGHT))

	//{

	//	character->setState(WalkBackwardsState::getInstance());

	//}

	//else if (IsKeyPressed(KEY_SPACE))

	//{

	//	character->setState(JumpState::getInstance());

	//}

	//…..

		// Add more states

}


CharacterState& WalkBackwardState::getInstance()

{

	static WalkBackwardState singleton;

	return singleton;

}