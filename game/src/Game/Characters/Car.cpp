#pragma once

#include "Game/Characters/Character.h"
#include "Car.h"
#include "Game/Characters/Ken.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"
#include "Game/Managers/TexturesManager.h"

#include <string>             // String manipulation functions: strrchr(), strcmp()

#include "raylib.h"


void Car::InitGameCharacter()
{
	setPosition(GetScreenWidth() / 2.0f -840, GetScreenHeight() / 2.0f + 140); //posicion inicial
	CarSprites_Counter = 8;
	CarSprites[0] = FrameRecPos{ {0,0,725,360}, {0.f, 0.f} };
	CarSprites[1] = FrameRecPos{ {0,360,725,360}, {-10.f, 30.f} };
	CarSprites[2] = FrameRecPos{ {0,688,715,360}, {-5.f, 30.f} };
	CarSprites[3] = FrameRecPos{ {725,688,725,360}, {-45.f, 30.f} };
	CarSprites[4] = FrameRecPos{ {35,1035,680,325}, {-50.f, 15.f} };
	CarSprites[5] = FrameRecPos{ {725,1035,680,325}, {-60.f, 7.f} };
	CarSprites[6] = FrameRecPos{ {35,1350,672,265}, {-55.f, -60.f} };
	CarSprites[7] = FrameRecPos{ {710,1350,672,265}, {-180.f, -60.f} };

	damage = CarSprites_Counter;
	bodyColliderRect = { getPosition().x + 75, getPosition().y + 30, 600, 300 };
}

void Car::UpdateGameCharacter(float deltaTime)
{
	framesCounter++;
	bodyColliderRect = { getPosition().x + 75, getPosition().y + 30, 600, 300 }; //actualizar el collider

}

void Car::DrawGameCharacter()
{
	TextureManager& textureManager = TextureManager::GetTextureManager();
	characterText = textureManager.GetTexture(TextureType::SpriteCar);
	//pintar ruedas
	DrawTextureRec(characterText, CarSprites[0].frameRec,
		Vector2{ getPosition().x - CarSprites[0].frameOrigin.x,
		getPosition().y - CarSprites[0].frameOrigin.y }, WHITE);

		DrawTextureRec(characterText, CarSprites[CarSprites_Counter-(damage-1)].frameRec,
			Vector2{ getPosition().x - CarSprites[CarSprites_Counter - (damage - 1)].frameOrigin.x,
			getPosition().y - CarSprites[CarSprites_Counter - (damage - 1)].frameOrigin.y }, WHITE);
		

}

void Car::UnloadGameCharacter()
{
}

void Car::setDamage(int damage)
{
	if (this->damage > 0) {
		this->damage -= damage;
	}
}

int Car::getDamage()
{
	return damage;
}


