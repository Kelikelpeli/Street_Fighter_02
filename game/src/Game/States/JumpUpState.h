#pragma once
#include "CharacterState.h"

class JumpState : public CharacterState {
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}

    StateType getStateType() const override { return StateType::JumpUp; }

    static JumpState& getInstance();

private:
    JumpState() {}
};
