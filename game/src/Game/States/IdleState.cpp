#include "IdleState.h"
#include "WalkForwardState.h"
#include "WalkBackwardState.h"
#include "JumpUpState.h"
#include "raylib.h"
#include "CharacterState.h"


//class IdleState : public CharacterState
//
//{
//    characterState->setCurrentFrame(0);
//    character->setFrameSpeed(8);
//}
void IdleState::enter(Character* character)
{
    // Set the character's state to Idle (e.g., animation or log)
    character->setState(CharSpriteDirection::State_Idle);
}

void IdleState::updateState(Character* character)
{
    // Handle state transitions
    if (IsKeyPressed(KEY_RIGHT))
    {
        character->setState(WalkForwardState::getInstance());
    }
    else if (IsKeyPressed(KEY_LEFT))
    {
        character->setState(WalkBackwardState::getInstance());
    }
    else if (IsKeyPressed(KEY_SPACE))
    {
        character->setState(JumpState::getInstance());
    }
}

CharacterState& IdleState::getInstance()
{
    static IdleState singleton;
    return singleton;
}

//int IdleState::getStateID() const
//{
//    return static_cast<int>(CharSpriteDirection::State_Idle);
//}


//#include "IdleState.h"
//
//
//	void IdleState::enter(GameCharacter* character)
//{
//	//character->SetCharSpriteState(CharSpriteDirection::State_Idle);
//		character->setCurrentFrame(0); // Reinicia la animación al entrar en Idle
//		character->setFrameSpeed(8);   // Ajusta la velocidad de animación para Idle
//}
//
//void IdleState::updateState(GameCharacter* character)
//{
//	// if (IsKeyPressed(KEY_LEFT))
//	// {
//		// character->setState(WalkForwardState::getInstance());
//
//	// }
//	// else if (IsKeyPressed(KEY_RIGHT))
//	// {
//		// character->setState(WalkBackwardsState::getInstance());
//	// }
//
//	// add more states
//	if (IsKeyPressed(KEY_RIGHT))
//	{
//		// Transición a estado de caminar hacia adelante
//		character->setState(WalkForwardState::getInstance());
//	}
//	else if (IsKeyPressed(KEY_LEFT))
//	{
//		// Transición a estado de caminar hacia atrás
//		character->setState(WalkBackwardState::getInstance());
//	}
//	else if (IsKeyPressed(KEY_SPACE))
//	{
//		// Transición a estado de salto
//		character->setState(JumpUpState::getInstance());
//	}
//	character->incrementFrameCounter();
//	if (character->getFrameCounter() >= (60 / character->getFrameSpeed()))
//	{
//		character->resetFrameCounter();
//		int currentFrame = character->getCurrentFrame();
//		currentFrame++;
//
//		if (currentFrame > 3) // Suponiendo que hay 4 frames para Idle
//		{
//			currentFrame = 0;
//		}
//
//		character->setCurrentFrame(currentFrame);
//	}
//
//}
//
//CharacterState& IdleState::getInstance()
//{
//	static IdleState singleton;
//	return singleton;
//}
//int IdleState::getStateID() const
//{
//	return static_cast<int>(CharSpriteDirection::State_Idle);
//}
// 