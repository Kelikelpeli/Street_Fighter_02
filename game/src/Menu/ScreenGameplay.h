#pragma once
#include "StateMachineMngr.h"
#include "Game/Characters/Car.h"
#include "Game/Characters/Ken.h"
#include "Game/Characters/Character.h"

#include "raylib.h"
#include <map>
#include <vector>

enum class UISprite {
	UISprite_0,
	UISprite_1,
	UISprite_2,
	UISprite_3,
	UISprite_4,
	UISprite_5,
	UISprite_6,
	UISprite_7,
	UISprite_8,
	UISprite_9
};
struct FrameRecUI {
	Rectangle frameRec;
	Vector2 frameOrigin;
};

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




private:
	ScreenGameplayState();
	ScreenGameplayState(const ScreenGameplayState& other);
	ScreenGameplayState& operator= (const ScreenGameplayState& other);

	void EvaluateInput();
	
	void DebugOptions();
	void DrawDebug();
	void CarDamage();
	void DrawCounter();

	int UISprites_Counter = 10;
	//std::map<UISprite, FrameRecUI> UISpritesMap;
	std::map<int, FrameRecUI> UISpritesMap;


	int framesCounter = 0;
	int finishScreen = 0;
	double countdown = 2400;
	int frame;
	int frame2;
	bool mb_ReplayLevel = false;
	bool win = false;


	bool debug_floor = false;
	bool debug_stairs = false;

	double startTime;
	Texture2D landscape;
	Texture2D ui;
	Ken* ken;
	Car* car;

};