#pragma once
#ifndef Car_CHAR_H
#define Car_CHAR_H
#include <map>
#include <string>

#include "Game/Characters/Character.h"

class Car : public GameCharacter {
public:
	virtual void InitGameCharacter() override;
	virtual void UpdateGameCharacter(float deltaTime) override;
	virtual void DrawGameCharacter() override;
	virtual void UnloadGameCharacter() override;
	void setDamage(int damage);
	int getDamage();

private:
	int damage;
};
#endif