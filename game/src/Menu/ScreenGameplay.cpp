
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/TexturesManager.h"
#include "Game/Managers/AudioManager.h"

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
	framesCounter = 0;
	finishScreen = 0;
	countdown = 2400;
	win = false;
	ken.InitCharacter();
}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	EvaluateInput();
	framesCounter++;
	countdown--;
	if (countdown <= 0) {
		finishScreen = 2;
	}
	ken.UpdateCharacter(deltaTime);
}

void ScreenGameplayState::DrawScreen(void)
{
	DrawRectangle(GetScreenHeight() / 2, GetScreenWidth() / 2, 100, 100, RED);


	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();
	
	// UI Score, lives

	Font font = GameInst.GetFont();

	DrawText("SCORE:", 300.f, 100.f, 25, WHITE);
	DrawText(to_string(GameInst.GetScore()).c_str(), 440.f, 100.f, 25, WHITE);

	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D landscape = textureManager.GetTexture(TextureType::Landscape);
	Vector2 centerScreen = { GetScreenWidth()/2.0f, (GetScreenHeight()) / 2.0f};

	textureManager.DrawTextureExCustom(landscape, centerScreen, 0, 1, WHITE);

	//ken.DrawCharacter();  // Dibujar a Ken



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
bool ScreenGameplayState::HasWin() {
	return win;
}
void ScreenGameplayState::SetWin(bool win) {
	this->win = win;
}