
#include "IdleState.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"


void IdleState::enter(GameCharacter* character)

{

	character->SetCharSpriteState(CharSpriteDirection::State_Idle);

}


void IdleState::updateState(GameCharacter* character)

{

	if (IsKeyPressed(KEY_LEFT))

	{

		character->setState(WalkForwardState::getInstance());

	}

	else if (IsKeyPressed(KEY_RIGHT))

	{

		character->setState(WalkBackwardState::getInstance());

	}

	else if (IsKeyPressed(KEY_SPACE))

	{

	//	character->setState(JumpState::getInstance());

	}

	
		// Add more states

}


CharacterState& IdleState::getInstance()

{

	static IdleState singleton;

	return singleton;

}