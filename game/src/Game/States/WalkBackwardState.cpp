
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"


void WalkBackwardState::enter(GameCharacter* character)

{

	character->SetCharSpriteState(CharSpriteDirection::State_WalkBackward);

}


void WalkBackwardState::updateState(GameCharacter* character)

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


CharacterState& WalkBackwardState::getInstance()

{

	static WalkBackwardState singleton;

	return singleton;

}