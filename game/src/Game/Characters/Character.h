#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <map>

class CharacterState;
#pragma once

enum class CharSpriteDirection
{
	State_Idle = 0,
	State_WalkForward,
	State_WalkBackward,
	State_Crouch,
	State_JumpUp,
	State_LightPunch,
	State_MediumPunch

};

struct FrameRecPos
{
	Rectangle frameRec;
	Vector2   frameOrigin;
};


class Character
{
public :
	Character();

	//virtual ~Character(); //


	virtual void InitCharacter();
	virtual void UpdateCharacter(float deltaTime);
	virtual void DrawCharacter();
	virtual void UnloadCharacter();

	//
	// Position management
	void setPosition(Vector2 newPosition) { position = newPosition; }
	Vector2 getPosition() const { return position; }

	// Movement management
	void setSpeed(Vector2 newSpeed) { speed = newSpeed; }
	Vector2 getSpeed() const { return speed; }
	void applyMovementLimits(Rectangle bounds);
	bool isWithinBounds(Rectangle bounds) const;

	// Collision management
	Rectangle getCollisionBox() const { return collisionBox; }
	void setCollisionBoxSize(Vector2 size) { collisionBox.width = size.x; collisionBox.height = size.y; }
	bool checkCollision(const Rectangle& other) const;


	// Damage handling
	virtual void takeDamage(int damageAmount);
	void heal(int amount);
	int getHealth() const { return health; }
	void setHealth(int newHealth) { health = (newHealth > maxHealth) ? maxHealth : newHealth; }
	bool isAlive() const { return health > 0; }

	// Animation management
	void setFrameSpeed(int newSpeed) { framesSpeed = newSpeed; }
	int getFrameSpeed() const { return framesSpeed; }
	void setCurrentFrame(int frame) { currentFrame = frame; }
	int getCurrentFrame() const { return currentFrame; }

	void incrementFrameCounter() { framesCounter++; }
	void resetFrameCounter() { framesCounter = 0; }
	int getFrameCounter() const { return framesCounter; }


	inline CharacterState* getCurrentState() const { return currentState; }
	void updateState();
	void setState(CharacterState& newState);
	//


protected:

	CharacterState* currentState;//

	std::map<CharSpriteDirection, int> CharSprites_Counter;
	
	std::map<int, FrameRecPos> CharSprites_Idle;
	std::map<int, FrameRecPos> CharSprites_WalkForward;
	std::map<int, FrameRecPos> CharSprites_WalkBackward;
	std::map<int, FrameRecPos> CharSprites_Crouch;
	std::map<int, FrameRecPos> CharSprites_JumpUp;
	std::map<int, FrameRecPos> CharSprites_LightPunch;
	std::map<int, FrameRecPos> CharSprites_MediumPunch;

	//
	int framesCounter = 0;
	int framesSpeed = 10;
	int currentFrame = 0;

	Vector2 position = { 0.0f, 0.0f };
	Vector2 speed = { 0.0f, 0.0f };

	// Collision box
	Rectangle collisionBox = { 0.0f, 0.0f, 50.0f, 50.0f }; // Default collision box size (to be updated as needed)

	// Health
	int health = 100;
	int maxHealth = 100;


	/*int CarSprites_Counter = 10;
	std::map<int, FrameRecPos> CarSprites;*/

//
//public:	
//	int framesCounter = 0;
//	int framesSpeed = 10;
//	int currentFrame = 0;
//
//	// State Mahines functions
//	inline CharacterState* getCurrentState() const { return currentState; }
//	// In here, we'll delegate the state transition to the currentState
//	void updateState();
//	// This will get called by the current state
//	void setState(CharacterState& newState);
//
//protected:
//		
//	CharacterState* currentState;


};

#endif 

