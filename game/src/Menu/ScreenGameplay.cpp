
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/TexturesManager.h"
#include "Game/Managers/AudioManager.h"

#include <string>

ScreenGameplayState::ScreenGameplayState(){}

ScreenGameplayState& ScreenGameplayState::getInstance()
{
	static ScreenGameplayState singleton;
	return singleton;
}

void ScreenGameplayState::InitScreen(void)
{
	TraceLog(LOG_INFO, "ScreenGameplayState::InitScreen");

	framesCounter = 0;
	finishScreen = 0;

	AudioManager& audioManager = AudioManager::GetAudioManager(); 
	GameManager& GameInst = GameManager::GetGameManager();

	audioManager.PlaySoundEffect(SoundType::KenTheme);
	GameInst.SetSeconds(0);
	GameInst.SetScore(false);

	// Prepare the map for the counter
	UISprites_Counter = 10;
	UISpritesMap[0] = FrameRecUI{ {58,125,60,60}, {0.f, 0.f} };
	UISpritesMap[1] = FrameRecUI{ {123,125,60,60}, {0.f, 0.f} };
	UISpritesMap[2] = FrameRecUI{ {188,125,60,60}, {0.f, 0.f} };
	UISpritesMap[3] = FrameRecUI{ {252,125,60,60}, {0.f, 0.f} };
	UISpritesMap[4] = FrameRecUI{ {316,125,60,60}, {0.f, 0.f} };
	UISpritesMap[5] = FrameRecUI{ {380,125,60,60}, {0.f, 0.f} };
	UISpritesMap[6] = FrameRecUI{ {443,125,60,60}, {0.f, 0.f} };
	UISpritesMap[7] = FrameRecUI{ {508,125,60,60}, {0.f, 0.f} };
	UISpritesMap[8] = FrameRecUI{ {569,125,60,60}, {0.f, 0.f} };
	UISpritesMap[9] = FrameRecUI{ {633,125,60,60}, {0.f, 0.f} };

	// Initialize "players"
	car = new Car();
	ken = new Ken();
	car->InitGameCharacter();
	ken->InitGameCharacter();

	// Variables to control the counter
	startTime = GetTime();
	countdown = GetTime();
	frame = 0; //second number
	frame2 = 4; //first number

	// Control damage per type of hit
	acumulacionDaño = 0; 
}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	GameManager& GameInst = GameManager::GetGameManager();

	EvaluateInput();

	ken->UpdateGameCharacter(deltaTime);
	car->UpdateGameCharacter(deltaTime);

	CarDamage(); 

	
	GameInst.SetSeconds(GetTime() - startTime);
	if (car->getDamage() <= 1) {
		GameInst.SetScore(true); //win
	}
	else if (car->getDamage() > 1) {
		GameInst.SetScore(false); //game over
	}
	if (GameInst.GetSeconds() > 40.f) {		
		finishScreen = 4; //ENDING
	}
}

void ScreenGameplayState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();
	TextureManager& textureManager = TextureManager::GetTextureManager();

	Font font = GameInst.GetFont();
	landscape = textureManager.GetTexture(TextureType::Landscape);

	DrawTexture(landscape, 0, 0, WHITE);

	ken->DrawGameCharacter();
	car->DrawGameCharacter();

	DrawCounter();
}

// Logic for car damage
void ScreenGameplayState::CarDamage()
{
	GameManager& GameInst = GameManager::GetGameManager();

	if (ken->GetAttack() && CheckCollisionRecs(ken->getHitColliderRect(), car->getBodyColliderRect())) {
		if (IsKeyPressed(KEY_Q)) {
			acumulacionDaño += 0.25f; // Light hit does less damage, faster
		}
		else if (IsKeyPressed(KEY_T)) {
			acumulacionDaño += 0.5f;  // Heavy hit, more damage, slower
		}
		if (acumulacionDaño >= 1.f) {
			acumulacionDaño = 0;
			car->setDamage(1); // Changes the car's frame
		}
	}
}

// Draw the counter
void ScreenGameplayState::DrawCounter()
{
	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D ui = textureManager.GetTexture(TextureType::UIMiscBig);

	float uiPosY = 20.f; //Height
	float separacion = 60.f;
	double segundo = GetTime() - countdown;

	//first number
	DrawTextureRec(ui, UISpritesMap[frame2].frameRec, Vector2{ GetScreenWidth() / 2.f - (separacion / 2),uiPosY }, WHITE);
	//second number
	DrawTextureRec(ui, UISpritesMap[frame].frameRec, Vector2{ GetScreenWidth() / 2.f + (separacion / 2),uiPosY }, WHITE);

	// Logic for changing the sprite every secon
	if (segundo >= 1.0f) {
		if (frame2 >= 0) {
			if (frame > 0) {
				frame--;
			}
			else {
				frame = 9;
				frame2--;
			}
			countdown = GetTime();
		}
		else {
			frame = 9;
			frame2 = 9;
		}
	}
}
void ScreenGameplayState::UnloadScreen(void){}

int  ScreenGameplayState::FinishScreen(void)
{
	return finishScreen;
}

void ScreenGameplayState::EvaluateInput()
{
	// Not necessary in logic, left for debugging and fixing errors
	
	/*if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 4;   // END SCREEN
	}*/
}

void ScreenGameplayState::DebugOptions(){}

void ScreenGameplayState::DrawDebug(){}