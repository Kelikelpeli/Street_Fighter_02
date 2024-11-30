#include "ScreenOptions.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"


ScreenOptionsState::ScreenOptionsState()
{

}

ScreenOptionsState& ScreenOptionsState::getInstance()
{
	static ScreenOptionsState singleton;
	return singleton;
}

void ScreenOptionsState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
}

void ScreenOptionsState::UpdateScreen(float deltaTime)
{
	if (IsKeyPressed(KEY_O))
	{
		finishScreen = 1;   // TITLE
	}
}

void ScreenOptionsState::DrawScreen(void)
{
	GameManager& GameInst = GameManager::GetGameManager();
	Font font = GameInst.GetFont();

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    const char* line1 = "Move your character using the arrow keys and press Space to jump.";
    const char* line2 = "Attack the car using Q or T.";
    const char* line3 = "Destroy the car before the timer reaches 0 to win!";
    

   // DrawText(line1, (GetScreenWidth() / 2) - (MeasureText(line1, 20) / 2.), 150, 20, WHITE);
	DrawTextEx(font, line1, Vector2{ (GetScreenWidth() - MeasureTextEx(font, line1, 25, 2).x) / 2.f, 150.f }, 25, 2, WHITE);
	DrawTextEx(font, line2, Vector2{ (GetScreenWidth() - MeasureTextEx(font, line2, 25, 2).x) / 2.f, 180.f }, 25, 2, WHITE);
	DrawTextEx(font, line3, Vector2{ (GetScreenWidth() - MeasureTextEx(font, line3, 25, 2).x) / 2.f, 210.f }, 25, 2, WHITE);

    //DrawText(line2, (GetScreenWidth() / 2) - (MeasureText(line2, 20) / 2.), 180, 20, WHITE);
   // DrawText(line3, (GetScreenWidth() / 2) - (MeasureText(line3, 20) / 2.), 210, 20, WHITE);

    const char* line7 = "Press 'O' to return to Title.";

   // DrawText(line7, (GetScreenWidth() / 2.f) - (MeasureText(line7, 20) / 2.), 380, 20, WHITE);
	DrawTextEx(font, line7, Vector2{ (GetScreenWidth() - MeasureTextEx(font, line7, 25, 2).x) / 2.f, 380.f }, 25, 2, WHITE);



}

void ScreenOptionsState::UnloadScreen(void)
{

}

int ScreenOptionsState::FinishScreen(void)
{
	return finishScreen;
}