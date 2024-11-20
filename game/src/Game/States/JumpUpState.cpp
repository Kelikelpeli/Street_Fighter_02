#include "JumpUpState.h"
#include "Game\Characters\Character.h"
#include "IdleState.h"

JumpUpState& JumpUpState::getInstance() {
    static JumpUpState instance;
    return instance;
}

void JumpUpState::enter(Character* character) {
    character->setStateAnimation(StateType::JumpUp);
    // Optional: Set vertical velocity or jumping logic
}

void JumpUpState::updateState(Character* character) {
    // Example: Return to Idle after landing
    if (!IsKeyDown(KEY_UP)) {
        character->setState(IdleState::getInstance());
    }
}
