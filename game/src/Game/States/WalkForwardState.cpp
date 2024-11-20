#include "WalkForwardState.h"
#include "Game\Characters\Character.h"
#include "CrouchState.h"
#include "IdleState.h"

WalkForwardState& WalkForwardState::getInstance() {
    static WalkForwardState instance;
    return instance;
}

void WalkForwardState::enter(Character* character) {
    character->setStateAnimation(StateType::WalkForward);
}

void WalkForwardState::updateState(Character* character) {
    if (IsKeyPressed(KEY_DOWN)) {
        character->setState(CrouchState::getInstance());
    }
    else if (!IsKeyDown(KEY_RIGHT)) {
        character->setState(IdleState::getInstance());
    }
}
