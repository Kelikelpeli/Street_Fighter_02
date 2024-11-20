#pragma once
#include "CharacterState.h"

class IdleState : public CharacterState {
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}

    StateType getStateType() const override { return StateType::Idle; }

    static IdleState& getInstance();

private:
    IdleState() {}
};
