#pragma once

#include "raylib.h"
#include "Game/Characters/Ken.h"

enum class TextureType
{
	Logo = 0,
	BonusKen,
	BasicSpriteKen,
	SpriteKenWalkLeft,
	SpriteKenClimb,
	SpriteKenClimbIdle,
	SpriteKenDead,
	SpriteKenDeadIdle,

	ImgCake,
	EnemyBarrelImg,

	Landscape,
	ImgBonus2,
	ImgBonus3,

	ImgPeach,

	ImgBurningBarrel,
	ImgFireFlame,
	ImgDonkeyKong,

	IconLifes,
};

enum class KenSpriteDirection
{
	KenSpriteIdleRight,
	KenSpriteIdleLeft,
	KenSpriteRight,
	KenSpriteLeft,
	KenSpriteClimb,
	KenSpriteClimbIdle,
	KenSpriteDead,
	KenSpriteDeadIdle
};

class TextureManager
{
public:
	TextureManager();

	void InitTexturesFiles();
	void UnloadTexturesFiles();

	//Functons For textures
	Texture2D& GetTexture(TextureType texture);
	Texture2D& GetTextureByCurrentState(KenSpriteDirection KenSpriteState);


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
	Texture2D textSpriteKenWalkLeft;
	Texture2D textSpriteKenClimb;
	Texture2D textSpriteKenClimbIdle;
	Texture2D textSpriteKenDead;
	Texture2D textSpriteKenDeadIdle;

	Texture2D textCake;
	Texture2D textBarrel;

	Texture2D textLandscape;
	Texture2D textBonus2;
	Texture2D textBonus3;

	Texture2D textPeach;

	Texture2D textBurningBarrel;
	Texture2D textFireFlame;
	Texture2D textDonkeyKong;

	//UI
	Texture2D textIconLifes;

	
};