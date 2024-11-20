#pragma once
#include "CharacterState.h"

class JumpUpState : public CharacterState {
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}

    StateType getStateType() const override { return StateType::JumpUp; }

    static JumpUpState& getInstance();

private:
    JumpUpState() {}
};
