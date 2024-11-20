
#include "IdleState.h"
#include "Game\Characters\Character.h"

#include "WalkForwardState.h"

#include "WalkBackwardState.h"
#include "JumpUpState.h"
#include "CrouchState.h"


void IdleState::enter(Character* character)

{

	character->SetCharSpriteState(CharSpriteDirection::State_Idle);

}


void IdleState::updateState(Character* character)

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

		character->setState(JumpUpState::getInstance());

	}


		// Add more states

}


CharacterState& IdleState::getInstance()

{

	static IdleState singleton;

	return singleton;

}