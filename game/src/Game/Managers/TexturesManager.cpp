#include "TexturesManager.h"

#include "Game/Characters/Ken.h"

TextureManager* TextureManager::TextureMngr = nullptr;

TextureManager::TextureManager()
{
    InitTexturesFiles();
}

TextureManager& TextureManager::GetTextureManager()
{
    if (!TextureMngr)
        TextureMngr = new TextureManager();

    return *TextureMngr;
}


void TextureManager::InitTexturesFiles()
{
    // Menu
    textLogo = LoadTexture("resources/Menu/Title.png");

    //Bonus Images
    bonusKen = LoadTexture("resources/Menu/KenBonusCar.png");


    //Gameplay
    // Basic Sprite Ken
    Image basicSpriteKen = LoadImage("resources/Game/Sprites/Ken/KenBasicMovementsSprites.png");
    textBasicSpriteKen = LoadTextureFromImage(basicSpriteKen);
    UnloadImage(basicSpriteKen);

    // Sprite Ken
    Image spriteKenLeft = LoadImage("resources/Characters/Mario_walk_left.png");
    textSpriteKenWalkLeft = LoadTextureFromImage(spriteKenLeft);
    UnloadImage(spriteKenLeft);
   
    // Sprite Ken Climb
    Image spriteKenClimb = LoadImage("resources/Characters/Mario_Climb.png");
    textSpriteKenClimb = LoadTextureFromImage(spriteKenClimb);
    UnloadImage(spriteKenClimb);

    // Sprite Ken Climb idle
    Image spriteKenClimbIdle = LoadImage("resources/Characters/Mario_Idle_Climb.png");
    textSpriteKenClimbIdle = LoadTextureFromImage(spriteKenClimbIdle);
    UnloadImage(spriteKenClimbIdle);

    // Sprite Ken Dead
    Image spriteKenDead = LoadImage("resources/Characters/Mario_Death.png");
    textSpriteKenDead = LoadTextureFromImage(spriteKenDead);
    UnloadImage(spriteKenDead);

    // Sprite Ken Dead idle
    Image spriteKenDeadIdle = LoadImage("resources/Characters/Mario_Death_Idle.png");
    textSpriteKenDeadIdle = LoadTextureFromImage(spriteKenDeadIdle);
    UnloadImage(spriteKenDeadIdle);

    //Car
    Image EnemyCakeImg = LoadImage("resources/Enemies/Cake.png");
    textCake = LoadTextureFromImage(EnemyCakeImg);
    UnloadImage(EnemyCakeImg);

    Image EnemyBarrelImg = LoadImage("resources/Enemies/Barrel.png");
    textBarrel = LoadTextureFromImage(EnemyBarrelImg);
    UnloadImage(EnemyBarrelImg);

    //Landscape
    Image landscape = LoadImage("resources/Game/Stages/Ken_Landscape_High.png");
    textLandscape = LoadTextureFromImage(landscape);
    UnloadImage(landscape);

    Image Bonus2Img = LoadImage("resources/Bonus/Bonus2.png");
    textBonus2 = LoadTextureFromImage(Bonus2Img);
    UnloadImage(Bonus2Img);

    Image Bonus3Img = LoadImage("resources/Bonus/Bonus3.png");
    textBonus3 = LoadTextureFromImage(Bonus3Img);
    UnloadImage(Bonus3Img);

    //Peach
    Image PeachImg = LoadImage("resources/Characters/Peach.png");
    textPeach = LoadTextureFromImage(PeachImg);
    UnloadImage(PeachImg);

    //Burning Barrel
    Image BurningBarrelImg = LoadImage("resources/Enemies/BurningBarrel.png");
    textBurningBarrel = LoadTextureFromImage(BurningBarrelImg);
    UnloadImage(BurningBarrelImg);

    //FireFlame
    Image FireFlameImg = LoadImage("resources/Enemies/FireFlame.png");
    textFireFlame = LoadTextureFromImage(FireFlameImg);
    UnloadImage(FireFlameImg);

    //Donkey Kong
    Image DonkeyKongImg = LoadImage("resources/Enemies/DonkeyKong.png");
    textDonkeyKong = LoadTextureFromImage(DonkeyKongImg);
    UnloadImage(DonkeyKongImg);

    //UI Mario Lifes
    Image KenLifesIconImg = LoadImage("resources/UI/MarioLifesIcon.png");
    textIconLifes = LoadTextureFromImage(KenLifesIconImg);
    UnloadImage(KenLifesIconImg);

}

Texture2D& TextureManager::GetTexture(TextureType texturetype)
{
    switch (texturetype)
    {
    case TextureType::Logo:
        return textLogo;
        break;

    case TextureType::BonusKen:
        return bonusKen;
        break;

    case TextureType::BasicSpriteKen:
        return textBasicSpriteKen;
        break;

    case TextureType::SpriteKenWalkLeft:
        return textSpriteKenWalkLeft;
        break;

    case TextureType::SpriteKenClimb:
        return textSpriteKenClimb;
        break;

    case TextureType::SpriteKenClimbIdle:
        return textSpriteKenClimbIdle;
        break;

    case TextureType::SpriteKenDead:
        return textSpriteKenDead;
        break;

    case TextureType::SpriteKenDeadIdle:
        return textSpriteKenDeadIdle;
        break;

    case TextureType::ImgCake:
        return textCake;
        break;

    case TextureType::EnemyBarrelImg:
        return textBarrel;
        break;

    case TextureType::Landscape:
        return textLandscape;
        break;

    case TextureType::ImgBonus2:
        return textBonus2;
        break;

    case TextureType::ImgBonus3:
        return textBonus3;
        break;

    case TextureType::ImgPeach:
        return textPeach;
        break;

    case TextureType::ImgBurningBarrel:
        return textBurningBarrel;
        break;

    case TextureType::ImgFireFlame:
        return textFireFlame;
        break;

    case TextureType::ImgDonkeyKong:
        return textDonkeyKong;
        break;
        
    case TextureType::IconLifes:
        return textIconLifes;
        break;

    default:
        break;
    }
}

Texture2D& TextureManager::GetTextureByCurrentState(KenSpriteDirection KenSpriteState)
{
    switch (KenSpriteState)
    {
    case KenSpriteDirection::KenSpriteIdleRight:
        return textBasicSpriteKen;
        break;
    case KenSpriteDirection::KenSpriteIdleLeft:
        return textSpriteKenWalkLeft;
        break;
    /*case KenSpriteDirection::KenSpriteRight:
        return textSpriteKenWalkRight;
        break;*/
    case KenSpriteDirection::KenSpriteLeft:
        return textSpriteKenWalkLeft;
        break;
    case KenSpriteDirection::KenSpriteClimb:
        return textSpriteKenClimb;
        break;
    case KenSpriteDirection::KenSpriteClimbIdle:
        return textSpriteKenClimbIdle;
        break;
    case KenSpriteDirection::KenSpriteDead:
        return textSpriteKenDead;
        break;
    case KenSpriteDirection::KenSpriteDeadIdle:
        return textSpriteKenDeadIdle;
        break;

    default:
        break;
    }
}




void TextureManager::DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
    Vector2 origin = { (float)texture.width / 2.f, (float)texture.height / 2.f };

    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void TextureManager::DrawTextureExCustomFromBottom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle dest = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
    Vector2 origin = { (float)texture.width / 2.f, (float)texture.height };

    DrawTexturePro(texture, source, dest, origin, rotation, tint);
}


void TextureManager::DrawTextureRecCustom(Texture2D texture, Rectangle Rectangle, Vector2 position, Color tint)
{
    Vector2 origin = { position.x - (Rectangle.width/2.f) , position.y - (Rectangle.height / 2.f) };
    DrawTextureRec(texture, Rectangle, origin, tint);
}

void TextureManager::UnloadTexturesFiles()
{
    UnloadTexture(textLogo);
    UnloadTexture(bonusKen);
    //UnloadTexture(textPacman);
    //UnloadTexture(textSpritePacman);
    //UnloadTexture(textSpritePacmanDead);
    //UnloadTexture(textIconLifes);
    //UnloadTexture(textSpriteEnemy);

}

