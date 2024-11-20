#include "WalkForwardState.h"
#include "IdleState.h"

void WalkForwardState::enter(Character* character)
{
    character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);
}

void WalkForwardState::updateState(Character* character)
{
    if (!IsKeyDown(KEY_RIGHT))
    {
        character->setState(IdleState::getInstance());
    }
    else
    {
        // Move character forward
        Vector2 position = character->GetPosition();
        position.x += character->GetSpeed();
        character->SetPosition(position);
    }
}

CharacterState& WalkForwardState::getInstance()
{
    static WalkForwardState singleton;
    return singleton;
}
