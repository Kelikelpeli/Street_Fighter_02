#pragma once
#include "CharacterState.h"

class CrouchState : public CharacterState {
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}

    StateType getStateType() const override { return StateType::Crouch; }

    static CrouchState& getInstance();

private:
    CrouchState() {}
};
