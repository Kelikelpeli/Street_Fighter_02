#include "WalkBackwardState.h"
#include "IdleState.h"

void WalkBackwardState::enter(Character* character)
{
    character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);
}

void WalkBackwardState::updateState(Character* character)
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

CharacterState& WalkBackwardState::getInstance()
{
    static WalkBackwardState singleton;
    return singleton;
}
