#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <map>
#include <vector>
#include <string>
#include "Game\States\CharacterState.h"
#include "Game\Managers\TexturesManager.h"

enum class StateType
{
	Idle = 0,
	WalkForward,
	WalkBackward,
	JumpUp,
	Crouch,
	LightPunch,
	MediumPunch
};
struct AnimationFrame
{
	Rectangle frameRec;    // Texture region
	Vector2 origin;        // Origin point for drawing
};


#pragma once


struct AnimationFrame
{
	Rectangle frameRec;
	Vector2   frameOrigin;
};


class Character
{
public :
	Character();

	virtual ~Character(); //


	virtual void InitCharacter(); // Initialize texture and animations
	virtual void UpdateCharacter(float deltaTime);
	virtual void DrawCharacter();

	//
	void SetPosition(Vector2 position);
    Vector2 GetPosition() const;
    void SetSpeed(float speed);
    float GetSpeed() const;

	inline CharacterState* getCurrentState() const { return currentState; }
	void updateState();
	void setState(CharacterState& newState);

	// Collision management
	virtual Rectangle GetCollisionBox() const;
		
	// Animation management
	void LoadAnimationFrames(StateType state, const std::vector<AnimationFrame>& frames);
	void setStateAnimation(StateType state);

	//void UpdateAnimation(float deltaTime);
	
protected:

	CharacterState* currentState;//

	std::map<StateType, std::vector<AnimationFrame>> animations;
	
	// Attributes
	Vector2 position;
	float speed;

	// Animation data
	size_t currentFrame;
	float frameCounter;
	float frameSpeed;
	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D characterText;
	// Collision box
	//Rectangle collisionBox = { 0.0f, 0.0f, 50.0f, 50.0f }; // Default collision box size (to be updated as needed)

	


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
//	CharacterState* currentState;


};

#endif 

