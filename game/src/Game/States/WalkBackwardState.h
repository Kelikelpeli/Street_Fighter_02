#pragma once

#include "CharacterState.h"
#include "Game\Characters\Character.h"

class WalkBackwardState : public CharacterState
{
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}
    static CharacterState& getInstance();

private:
    WalkBackwardState() {}
    WalkBackwardState(const WalkBackwardState&) = delete;
    WalkBackwardState& operator=(const WalkBackwardState&) = delete;
};
