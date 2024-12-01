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
    TraceLog(LOG_INFO, "ScreenIntroState::InitScreen");
    framesCounter = 0;
    finishScreen = 0;
    alpha = 0.0f;
    fadeDirection = 1;
}

void ScreenIntroState::UpdateScreen(float deltaTime)
{
    framesCounter++;

    // Controls the fade-in and fade-out effect
    if (fadeDirection == 1)
    {
        alpha += 0.02f;
        if (alpha >= 1.0f)
        {
            alpha = 1.0f;
            fadeDirection = 0; // Ends the fade-in
        }
    }
    else if (fadeDirection == -1)
    {
        alpha -= 0.02f;
        if (alpha <= 0.0f)
        {
            alpha = 0.0f;
            finishScreen = 1; //GAMEPLAY
        }
    }

    if (framesCounter > 180 && fadeDirection == 0)
    {
        fadeDirection = -1; // Starts the fade-out after a delay
    }
}

void ScreenIntroState::DrawScreen(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    TextureManager& textureManager = TextureManager::GetTextureManager(); // Accesses textures
    Texture2D bonusCarKen = textureManager.GetTexture(TextureType::BonusKen);
    Vector2 screenCenter = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f - 100 };

    textureManager.DrawTextureExCustom(bonusCarKen, screenCenter, 0, 1, WHITE); // Function managed and defined by the texture manager
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 1.0f - alpha)); // The actual fade effect is achieved with this rectangle
}

void ScreenIntroState::UnloadScreen(void){}

int ScreenIntroState::FinishScreen(void)
{
    return finishScreen;
}
