#pragma once

#include "raylib.h"
#include "Game/Characters/Ken.h"

enum class TextureType {
	Logo = 0,
	BonusKen,
	BasicSpriteKen,
	PunchSpriteKen,

	Landscape,
	SpriteCar,
	UIMiscBig,	
};

class TextureManager {
public:
	TextureManager();

	void InitTexturesFiles();
	void UnloadTexturesFiles();

	//Functions For textures
	Texture2D& GetTexture(TextureType texture);

	void DrawTextureExCustom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
	void DrawTextureExCustomFromBottom(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
	void DrawTextureRecCustom(Texture2D texture, Rectangle Rectangle, Vector2 position, Color tint);
	void DrawTextureOriginRec(Texture2D texture, Rectangle source, Vector2 position, Color tint, Vector2 origin);
	static TextureManager& GetTextureManager();

private:
	static TextureManager* TextureMngr;

	Texture2D textLogo;
	Texture2D bonusKen;
	Texture2D textBasicSpriteKen;
	Texture2D textPunchSpriteKen;

	Texture2D textLandscape;
	Texture2D textSpriteCar;
	Texture2D textUIMiscBig;	
};