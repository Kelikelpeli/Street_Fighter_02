#pragma once

#include "CharacterState.h"
#include "Game\Characters\Character.h"

class WalkForwardState : public CharacterState
{
public:
    void enter(Character* character) override;
    void updateState(Character* character) override;
    void exit(Character* character) override {}
    static CharacterState& getInstance();

private:
    WalkForwardState() {}
    WalkForwardState(const WalkForwardState&) = delete;
    WalkForwardState& operator=(const WalkForwardState&) = delete;
};
