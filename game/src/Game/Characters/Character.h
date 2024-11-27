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
	State_LightPunch,
	State_MediumPunch

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
	void MoveCharacter();




protected:
	std::map<CharSpriteDirection, std::map<int, FrameRecPos>> CharSprites;

	std::map<CharSpriteDirection, int> CharSprites_Counter;

	std::map<int, FrameRecPos> CharSprites_Idle;
	std::map<int, FrameRecPos> CharSprites_WalkForward;
	std::map<int, FrameRecPos> CharSprites_WalkBackward;
	std::map<int, FrameRecPos> CharSprites_Crouch;
	std::map<int, FrameRecPos> CharSprites_JumpUp;
	std::map<int, FrameRecPos> CharSprites_LightPunch;
	std::map<int, FrameRecPos> CharSprites_MediumPunch;

	int CarSprites_Counter = 10;
	std::map<int, FrameRecPos> CarSprites;

public:
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

	void setPosition(float x, float y);
	Vector2 getPosition();
	void setSpeed(float x, float y);
	Vector2 getSpeed();
	void isJump(bool jump);
	bool getJump();
	void isCrouch(bool crouch);
	bool getCrouch();

protected:
	CharSpriteDirection currentSpriteState;
	CharacterState* currentState;

	Vector2 position;
	Vector2 speed;
	Texture2D characterText = { 0 };
	bool jump=false;
	bool crouch;

};
#endif 
