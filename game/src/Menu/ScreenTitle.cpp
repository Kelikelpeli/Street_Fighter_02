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

	//Logo y animación
	LogoTitle = LoadTexture("resources/Menu/Title.png");
	animationStarted = false; // Variable para controlar el inicio de la animación
	animationComplete = false; // Controla si la animación ha finalizado
	rotationAngle = 0.0f;
	scale = 1.0f;

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

	//animación logo
	if (framesCounter > 30 && !animationStarted && !animationComplete)  // 120 frames ~ 2 segundos
	{
		animationStarted = true;
	}


	if (animationStarted && !animationComplete)
	{
		rotationAngle += 12.0f;   // Rota gradualmente
		scale += 0.005f;         // Aumenta el tamaño gradualmente

		if (rotationAngle >= 360.0f) // Completa una rotación completa
		{
			rotationAngle = 0.0f;
			scale = scale;          // Fija el tamaño final al 1.5 del original
			animationComplete = true; // Marca la animación como completa
			animationStarted = false;
		}
	}
}

void ScreenTitleState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	float posx = ((GetScreenWidth() / 2.f) - (MeasureText("by Raquel L.", 20) / 2.f));

	DrawTextEx(GameInst.GetFont(), " by Raquel L.", Vector2{ posx, 720.f }, 20, 4, WHITE);

	DrawText("Press Enter for Playing", (GetScreenWidth() / 2) - (MeasureText("Press Enter for Playing", 25) / 2), 800, 25, WHITE);
	DrawText("Press 'O' for Instructions", (GetScreenWidth() / 2) - (MeasureText("Press 'O' for Instructions", 25) / 2), 860, 25, WHITE);


	// Define la posición del logo en el centro de la pantalla
	Vector2 screenCenter = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 100 };

	// Establece el punto de origen en el centro del logo
	Vector2 origin = { LogoTitle.width / 2.0f, LogoTitle.height / 2.0f };

	// Usa DrawTexturePro para rotar desde el centro de la pantalla y escalar
	DrawTexturePro(
		LogoTitle,                                      // Textura
		Rectangle{ 0, 0, (float)LogoTitle.width, (float)LogoTitle.height },  // Rectángulo de origen
		Rectangle{ screenCenter.x, screenCenter.y, LogoTitle.width * scale, LogoTitle.height * scale }, // Rectángulo de destino
		Vector2{ LogoTitle.width * scale / 2, LogoTitle.height * scale / 2 }, // Centro de rotación
		rotationAngle,                                  // Ángulo de rotación
		WHITE                                           // Color de dibujo
	);
	//DrawTexture(LogoTitle, ((GetScreenWidth() / 2) - (LogoTitle.width / 2)), ((GetScreenHeight() / 2) - (LogoTitle.height / 2)) - 100, WHITE);

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