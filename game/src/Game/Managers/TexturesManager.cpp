#include "TexturesManager.h"

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
	Image punchSpriteKen = LoadImage("resources/Game/Sprites/Ken/KenPunchMovementsSprites.png");
	textPunchSpriteKen = LoadTextureFromImage(punchSpriteKen);
	UnloadImage(punchSpriteKen);

	//Landscape
	Image landscape = LoadImage("resources/Game/Stages/Ken_Landscape_High.png");
	textLandscape = LoadTextureFromImage(landscape);
	UnloadImage(landscape);

	Image spriteCar = LoadImage("resources/Game/Sprites/Car/CarBouns.png");
	textSpriteCar = LoadTextureFromImage(spriteCar);
	UnloadImage(spriteCar);

	Image UIMiscBigImg = LoadImage("resources/UI/UI_MiscBig.png");
	textUIMiscBig = LoadTextureFromImage(UIMiscBigImg);
	UnloadImage(UIMiscBigImg);
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

	case TextureType::PunchSpriteKen:
		return textPunchSpriteKen;
		break;

	case TextureType::Landscape:
		return textLandscape;
		break;

	case TextureType::SpriteCar:
		return textSpriteCar;
		break;

	case TextureType::UIMiscBig:
		return textUIMiscBig;
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
	Vector2 origin = { position.x - (Rectangle.width / 2.f) , position.y - (Rectangle.height / 2.f) };
	DrawTextureRec(texture, Rectangle, origin, tint);
}
void TextureManager::DrawTextureOriginRec(Texture2D texture, Rectangle source, Vector2 position, Color tint, Vector2 newOrigin = Vector2{ 0.f,0.f })
{
	Rectangle dest = { position.x, position.y, fabsf(source.width), fabsf(source.height) };

	Vector2 origin = newOrigin;

	DrawTexturePro(texture, source, dest, origin, 0.0f, tint);
}

void TextureManager::UnloadTexturesFiles()
{
	UnloadTexture(textLogo);
	UnloadTexture(bonusKen);
}

