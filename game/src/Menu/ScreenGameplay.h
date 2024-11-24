#pragma once
#include "StateMachineMngr.h"
#include "Game/Characters/Ken.h"
#include "Game/Characters/Character.h"


class ScreenGameplayState : public StateMachineMngr
{
public:

	void enter(Screen* screen) {}
	void toggle(Screen* screen) {};
	void exit(Screen* screen) {};

	virtual void InitScreen(void);
	virtual void UpdateScreen(float deltaTime);
	virtual void DrawScreen(void);
	virtual void UnloadScreen(void);
	virtual int FinishScreen(void);

	int getScreenId() { return (int)ScreenState::GAMEPLAY; }

	static ScreenGameplayState& getInstance();
	bool HasWin();


private:
	ScreenGameplayState();
	ScreenGameplayState(const ScreenGameplayState& other);
	ScreenGameplayState& operator= (const ScreenGameplayState& other);

	void EvaluateInput();
	
	void DebugOptions();
	void DrawDebug();

	void SetWin(bool win);

	int framesCounter = 0;
	int finishScreen = 0;
	int countdown = 2400;
	bool mb_ReplayLevel = false;
	bool win = false;


	bool debug_floor = false;
	bool debug_stairs = false;

	Texture2D landscape;
	Ken* ken;

};