#include "IdleState.h"
#include "raylib.h"

void IdleState::enter(Character* character)
{
    character->setCurrentFrame(0);
    character->setFrameSpeed(8);
}

void IdleState::updateState(Character* character)
{
    if (IsKeyPressed(KEY_RIGHT))
    {
        // Transici�n al estado de caminar hacia adelante
        //character->setState(WalkForwardState::getInstance());
    }

    // Actualizaci�n de la animaci�n usando la funci�n com�n
    updateAnimationFrame(character, 4); // Suponiendo 4 frames para el estado Idle
}

CharacterState& IdleState::getInstance()
{
    static IdleState singleton;
    return singleton;
}

int IdleState::getStateID() const
{
    return static_cast<int>(CharSpriteDirection::State_Idle);
}


//#include "IdleState.h"
//
//
//	void IdleState::enter(GameCharacter* character)
//{
//	//character->SetCharSpriteState(CharSpriteDirection::State_Idle);
//		character->setCurrentFrame(0); // Reinicia la animaci�n al entrar en Idle
//		character->setFrameSpeed(8);   // Ajusta la velocidad de animaci�n para Idle
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
//		// Transici�n a estado de caminar hacia adelante
//		character->setState(WalkForwardState::getInstance());
//	}
//	else if (IsKeyPressed(KEY_LEFT))
//	{
//		// Transici�n a estado de caminar hacia atr�s
//		character->setState(WalkBackwardState::getInstance());
//	}
//	else if (IsKeyPressed(KEY_SPACE))
//	{
//		// Transici�n a estado de salto
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