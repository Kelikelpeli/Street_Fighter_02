#pragma once

#include "CharacterState.h"
#include <Game/Characters/Character.h>

class BaseCharacterState : public CharacterState
{
public:
    virtual ~BaseCharacterState() {}

    // Implementaci�n com�n para actualizar el frame de animaci�n
    virtual void updateAnimationFrame(Character* character, int totalNumFrames)
    {
        character->incrementFrameCounter();
        if (character->getFrameCounter() >= (60 / character->getFrameSpeed()))
        {
            character->resetFrameCounter();
            int currentFrame = character->getCurrentFrame();
            currentFrame++;

            if (currentFrame >= totalNumFrames)
            {
                currentFrame = 0;
            }

            character->setCurrentFrame(currentFrame);
        }
    }

    // Se mantendr�n virtuales los m�todos de la clase base
    virtual void enter(Character* character) override = 0;
    virtual void updateState(Character* character) override = 0;
    virtual void exit(Character* character) override = 0;
};
