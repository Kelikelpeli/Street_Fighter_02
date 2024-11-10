#include "ScreenTitle.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"

ScreenTitleState& ScreenTitleState::getInstance()
{
	static ScreenTitleState singleton;
	return singleton;
}


void ScreenTitleState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
	TraceLog(LOG_INFO, "ScreenTitleState::InitScreen");
	LogoTitle= LoadTexture( "resources/Menu/Title.png");

	// Use this to access to the Game instance
	GameManager& GameInst = GameManager::GetGameManager();


}

void ScreenTitleState::UpdateScreen(float deltaTime)
{
	framesCounter++;
	GameManager& GameInst = GameManager::GetGameManager();


	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 2;   // GAMEPLAY
	}

	if (IsKeyPressed(KEY_O))
	{
		finishScreen = 1;   // OPTIONS
	}
}

void ScreenTitleState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	float posx = ((GetScreenWidth() / 2.f) - (MeasureText("by Raquel L.", 20) / 2.f));

	DrawTextEx(GameInst.GetFont(), " by Raquel L.", Vector2{ posx, 450.f }, 20, 4, WHITE);

	DrawText("Press Enter for Playing", (GetScreenWidth() / 2) - (MeasureText("Press Enter for Playing", 25) / 2), 800, 25, WHITE);
	DrawText("Press 'O' for Instructions", (GetScreenWidth() / 2) - (MeasureText("Press 'O' for Instructions", 25) / 2), 860, 25, WHITE);

	if(framesCounter<50){}
	DrawTexture(LogoTitle, ((GetScreenWidth()/2) - (LogoTitle.width/2)), ((GetScreenHeight()/2) - (LogoTitle.height/2))-100 , WHITE);


}

void ScreenTitleState::UnloadScreen(void)
{
	GameManager& GameInst = GameManager::GetGameManager();
	UnloadTexture(LogoTitle);
}

int ScreenTitleState::FinishScreen(void)
{
	return finishScreen;
}