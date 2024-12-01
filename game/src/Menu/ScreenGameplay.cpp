
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/TexturesManager.h"
#include "Game/Managers/AudioManager.h"

#include <string>
#include <iostream>


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
	AudioManager& audioManager = AudioManager::GetAudioManager();

	audioManager.PlaySoundEffect(SoundType::KenTheme);
	GameManager& GameInst = GameManager::GetGameManager();
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


	car = new Car();

	ken = new Ken();
	framesCounter = 0;
	finishScreen = 0;
	car->InitGameCharacter();
	ken->InitGameCharacter();
	GameInst.SetSeconds(0);
	GameInst.SetScore(false);
	startTime = GetTime();
	countdown = GetTime();
	frame = 1;
	frame2 = 4;
	acumulacionDa�o = 0;
}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	GameManager& GameInst = GameManager::GetGameManager();

	EvaluateInput();

	ken->UpdateGameCharacter(deltaTime);
	car->UpdateGameCharacter(deltaTime);
	CarDamage();
	GameInst.SetSeconds(GetTime() - startTime);
	if (GameInst.GetSeconds() > 41.0f) {
		if (car->getDamage() <= 0) {
			GameInst.SetScore(true); //ganar
		}
		else {
			GameInst.SetScore(false); //perder
		}
		finishScreen = 4;

	}


}

void ScreenGameplayState::DrawScreen(void)
{

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	// UI Score, lives

	Font font = GameInst.GetFont();

	//DrawText("SCORE:", 300.f, 100.f, 25, WHITE);
	//DrawText(to_string(GameInst.GetScore()).c_str(), 440.f, 100.f, 25, WHITE);
//	Vector2 centerScreen = Vector2{ (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	TextureManager& textureManager = TextureManager::GetTextureManager();
	landscape = textureManager.GetTexture(TextureType::Landscape);
	DrawTexture(landscape, 0, 0, WHITE);

	ken->DrawGameCharacter();
	car->DrawGameCharacter();
	DrawCounter();


}
void ScreenGameplayState::CarDamage()
{

	if (ken->GetAttack() && CheckCollisionRecs(ken->getHitColliderRect(), car->getBodyColliderRect())) {
		if (IsKeyPressed(KEY_Q)) {
			acumulacionDa�o += 0.25f; //golpe ligero hace menos da�o, m�s r�pidoa
		}
		else if (IsKeyPressed(KEY_T)) {
			acumulacionDa�o += 0.5f;  //golpe contundente, m�s da�o, m�s lento
		}
		if (acumulacionDa�o >= 1.f) {
			acumulacionDa�o = 0;
			car->setDamage(1);
		}
	}

}

//dibujar contador
void ScreenGameplayState::DrawCounter()
{
	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D ui = textureManager.GetTexture(TextureType::UIMiscBig);
	float uiPosY = 20.f;
	float separacion = 60.f;
	double segundo = GetTime() - countdown;
	//primer numero
	DrawTextureRec(ui, UISpritesMap[frame2].frameRec, Vector2{ GetScreenWidth() / 2.f - (separacion / 2),uiPosY }, WHITE);
	//segundo numero
	DrawTextureRec(ui, UISpritesMap[frame].frameRec, Vector2{ GetScreenWidth() / 2.f + (separacion / 2),uiPosY }, WHITE);

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