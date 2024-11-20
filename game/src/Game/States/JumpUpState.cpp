#include "JumpUpState.h"
#include "Game\Characters\Character.h"
#include "IdleState.h"

JumpState& JumpState::getInstance() {
    static JumpState instance;
    return instance;
}

void JumpState::enter(Character* character) {
    character->setStateAnimation(StateType::JumpUp);
    // Optional: Set vertical velocity or jumping logic
}

void JumpState::updateState(Character* character) {
    // Example: Return to Idle after landing
    if (!IsKeyDown(KEY_UP)) {
        character->setState(IdleState::getInstance());
    }
}
