#include "ScreenTitle.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/Managers/TexturesManager.h"
#include "Game/Managers/AudioManager.h"

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

	//Logo y animación
	animationStarted = false; 
	animationComplete = false; 
	rotationAngle = 0.0f;
	scale = 1.0f;

	// Use this to access to the Game instance
	GameManager& GameInst = GameManager::GetGameManager();
	AudioManager& audioManager = AudioManager::GetAudioManager();

	audioManager.PlaySoundEffect(SoundType::IntroTheme);
}

void ScreenTitleState::UpdateScreen(float deltaTime)
{

	framesCounter++;

	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 2;   // INTRO
	}

	if (IsKeyPressed(KEY_O))
	{
		finishScreen = 1;   // OPTIONS
	}

	// Logo and animation
	if (framesCounter > 30 && !animationStarted && !animationComplete)  // Waits before starting
	{
		animationStarted = true;
	}


	if (animationStarted && !animationComplete)
	{
		rotationAngle += 12.0f;      // Gradually rotates
		scale += 0.005f;             // Gradually increases size

		if (rotationAngle >= 360.0f) // Only one rotation
		{
			rotationAngle = 0.0f;
			scale = scale;           // Sets the final size
			animationComplete = true;
			animationStarted = false;
		}
	}
}

void ScreenTitleState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	//Texts
	const char* line1 = "Press Enter to go to Title screen";
	const char* line2 = "Press 'O' for Options";
	const char* line3 = "by Raquel L.";
	DrawTextEx(GameInst.GetFont(), line1, Vector2{ (GetScreenWidth() - MeasureTextEx(GameInst.GetFont(), line1, 25, 2).x) / 2.f, 800.f }, 25, 2, WHITE);
	DrawTextEx(GameInst.GetFont(), line2, Vector2{ (GetScreenWidth() - MeasureTextEx(GameInst.GetFont(), line2, 25, 2).x) / 2.f, 850.f }, 25, 2, WHITE);
	DrawTextEx(GameInst.GetFont(), line3, Vector2{ (GetScreenWidth() - MeasureTextEx(GameInst.GetFont(), line3, 25, 2).x) / 2.f, 720.f }, 25, 2, WHITE);

	//Title texture
	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D logoTexture = textureManager.GetTexture(TextureType::Logo);
	Vector2 screenCenter = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 100 };
	textureManager.DrawTextureExCustom(logoTexture, screenCenter, rotationAngle, scale, WHITE);
}

void ScreenTitleState::UnloadScreen(void)
{
	GameManager& GameInst = GameManager::GetGameManager();
}

int ScreenTitleState::FinishScreen(void)
{
	return finishScreen;
}