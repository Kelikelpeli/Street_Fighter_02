#ifndef CHARACTER_H
#define CHARACTER_H
#endif 

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


class GameCharacter
{
public :
	GameCharacter();

	virtual void InitGameCharacter();
	virtual void UpdateGameCharacter(float deltaTime);
	virtual void DrawGameCharacter();
	virtual void UnloadGameCharacter();




protected:

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

protected:
		
	CharacterState* currentState;


};


