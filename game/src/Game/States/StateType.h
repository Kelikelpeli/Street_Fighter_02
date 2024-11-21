#pragma once
#ifndef STATETYPES_H
#define STATETYPES_H
enum class StateType {
    Idle = 0,
    WalkForward,
    WalkBackward,
    JumpUp,
    Crouch,
    LightPunch,
    MediumPunch
};
#endif