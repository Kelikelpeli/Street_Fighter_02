#include "ScreenIntro.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/Managers/TexturesManager.h"

ScreenIntroState& ScreenIntroState::getInstance()
{
    static ScreenIntroState singleton;
    return singleton;
}

void ScreenIntroState::InitScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    TraceLog(LOG_INFO, "ScreenIntroState::InitScreen");
}

void ScreenIntroState::UpdateScreen(float deltaTime)
{
    framesCounter++;

    if (framesCounter > 180)
    {
        finishScreen = 1; // Indica que debe cambiar a la siguiente pantalla (GAMEPLAY)
    }
}

void ScreenIntroState::DrawScreen(void)
{
    TextureManager& textureManager = TextureManager::getInstance();
    textureManager.InitTexturesFiles();


    // Dibuja un rectángulo oscuro en toda la pantalla
    Texture2D bonusCarKen = textureManager.GetTexture(TextureType::BonusKen);

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    //DrawText("Intro Screen", GetScreenWidth() / 2 - MeasureText("Intro Screen", 20) / 2, GetScreenHeight() / 2, 20, RAYWHITE);

    Vector2 screenCenter = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 100 };

    textureManager.DrawTextureExCustom(bonusCarKen, screenCenter, 0, 1, WHITE);

}

void ScreenIntroState::UnloadScreen(void)
{
    TraceLog(LOG_INFO, "ScreenIntroState::UnloadScreen");
}

int ScreenIntroState::FinishScreen(void)
{
    return finishScreen;
}
