#pragma once
#include "StateMachineMngr.h"
#include "Screen.h"
#include "raylib.h"

class ScreenIntroState : public StateMachineMngr
{
public:
    void enter(Screen* screen) {}
    void toggle(Screen* screen) {}
    void exit(Screen* screen) {}

    void InitScreen(void);
    void UpdateScreen(float deltaTime);
    void DrawScreen(void);
    void UnloadScreen(void);
    int FinishScreen(void);

    int getScreenId() { return (int)ScreenState::INTRO; }

    static ScreenIntroState& getInstance();

private:
    ScreenIntroState() {};
    ScreenIntroState(const ScreenIntroState& other);
    ScreenIntroState& operator=(const ScreenIntroState& other);

    int framesCounter = 0;
    int finishScreen = 0;
    float alpha = 0.0f;
    int fadeDirection = 0;
};
