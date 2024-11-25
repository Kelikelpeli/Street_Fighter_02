
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/TexturesManager.h"

#include <string>


ScreenGameplayState::ScreenGameplayState()
{

}

ScreenGameplayState& ScreenGameplayState::getInstance()
{
	static ScreenGameplayState singleton;
	return singleton;
}

void ScreenGameplayState::InitScreen(void)
{
	ken = new Ken();
	framesCounter = 0;
	finishScreen = 0;
	ken->InitGameCharacter();

}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	EvaluateInput();

	ken->UpdateGameCharacter(deltaTime);
}

void ScreenGameplayState::DrawScreen(void)
{

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	// UI Score, lives

	Font font = GameInst.GetFont();

	DrawText("SCORE:", 300.f, 100.f, 25, WHITE);
	DrawText(to_string(GameInst.GetScore()).c_str(), 440.f, 100.f, 25, WHITE);
	Vector2 centerScreen = Vector2{(float) GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	TextureManager& textureManager = TextureManager::GetTextureManager();
	landscape = textureManager.GetTexture(TextureType::Landscape);
	DrawTexture(landscape, 0, 0, WHITE);

	ken->DrawGameCharacter();


}

void ScreenGameplayState::UnloadScreen(void)
{

}

int  ScreenGameplayState::FinishScreen(void)
{
	return finishScreen;
}

void ScreenGameplayState::EvaluateInput()
{

	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 4;   // END SCREEN
	}
}

void ScreenGameplayState::DebugOptions()
{

}

void ScreenGameplayState::DrawDebug()
{
	GameManager& GameInst = GameManager::GetGameManager();

}