
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"


void WalkForwardState::enter(GameCharacter* character)

{

	character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);

}


void WalkForwardState::updateState(GameCharacter* character)

{

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


CharacterState& WalkForwardState::getInstance()

{

	static WalkForwardState singleton;

	return singleton;

}