#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <map>
#include <vector>

class CharacterState;

enum class CharSpriteDirection
{
	State_Idle = 0,
	State_WalkForward,
	State_WalkBackward,
	State_Crouch,
	State_JumpUp,
	State_Special1,
	State_Special2

};

struct FrameRecPos
{
	Rectangle frameRec;
	Vector2   frameOrigin;
};


class GameCharacter
{
public:
	GameCharacter();

	virtual void InitGameCharacter();
	virtual void UpdateGameCharacter(float deltaTime);
	virtual void DrawGameCharacter();
	virtual void UnloadGameCharacter();

	int framesCounter = 0;
	int framesSpeed = 10;
	int currentFrame = 0;

	// State Mahines functions
	inline CharacterState* getCurrentState() const { return currentState; }
	// In here, we'll delegate the state transition to the currentState
	void updateState();
	// This will get called by the current state
	void setState(CharacterState& newState);
	void SetCharSpriteState(CharSpriteDirection newCharState);

	//Setters and getters
	void setPosition(float x, float y);
	Vector2 getPosition();
	void setSpeed(float x, float y);
	Vector2 getSpeed();
	void isStop(bool stop);
	bool getStop();
	Rectangle getBodyColliderRect();

	// For jump and attack logic in the state
	const float groundLevel = GetScreenHeight() / 2.0f + 100;
	bool GetAttack();
	void setAttack(bool attack);

protected:

	// Contains all types of sprites
	std::map<CharSpriteDirection, std::map<int, FrameRecPos>> CharSprites;

	std::map<CharSpriteDirection, int> CharSprites_Counter;

	std::map<int, FrameRecPos> CharSprites_Idle;
	std::map<int, FrameRecPos> CharSprites_WalkForward;
	std::map<int, FrameRecPos> CharSprites_WalkBackward;
	std::map<int, FrameRecPos> CharSprites_Crouch;
	std::map<int, FrameRecPos> CharSprites_JumpUp;
	std::map<int, FrameRecPos> CharSprites_Special1;
	std::map<int, FrameRecPos> CharSprites_Special2;

	// For the car case...
	int CarSprites_Counter = 10;
	std::map<int, FrameRecPos> CarSprites;

	CharSpriteDirection currentSpriteState;
	CharacterState* currentState;

	// Collisions
	Rectangle bodyColliderRect = { getPosition().x + 50, getPosition().y + 20, 170, 350 };

	Vector2 position;
	Vector2 widthLimits = { 0,(float)GetScreenWidth() };

	Vector2 speed;
	Texture2D characterText = { 0 }; //textura basica

	bool stop = false;
	bool attack;
};
#endif 
