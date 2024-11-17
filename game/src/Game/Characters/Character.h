#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <map>
#include <vector>
#include <string>

enum class CharState
{
	Idle = 0,
	WalkForward,
	WalkBackward,
	JumpUp,
	Crouch
};
struct AnimationFrame
{
	Rectangle frameRec;    // Texture region
	Vector2 origin;        // Origin point for drawing
};


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

	virtual ~Character(); //


	virtual void InitCharacter(); // Initialize texture and animations

	virtual void UpdateCharacter(float deltaTime);
	virtual void DrawCharacter();
	//virtual void UnloadCharacter();

	//
	void SetPosition(Vector2 position);
    Vector2 GetPosition() const;
    void SetSpeed(float speed);
    float GetSpeed() const;


	// State management
	void SetState(CharState state);
	CharState GetState() const;

	// Collision management
	virtual Rectangle GetCollisionBox() const;

	/*Rectangle getCollisionBox() const { return collisionBox; }
	void setCollisionBoxSize(Vector2 size) { collisionBox.width = size.x; collisionBox.height = size.y; }
	bool checkCollision(const Rectangle& other) const;*/


	
	// Animation management
	void LoadAnimationFrames(CharState state, const std::vector<AnimationFrame>& frames);
	void UpdateAnimation(float deltaTime);
	


protected:

	CharacterState* currentState;//

	std::map<CharSpriteDirection, int> CharSprites_Counter;
	
	std::map<int, FrameRecPos> CharSprites_Idle;
	std::map<int, FrameRecPos> CharSprites_WalkForward;
	std::map<int, FrameRecPos> CharSprites_WalkBackward;
	std::map<int, FrameRecPos> CharSprites_Crouch;
	std::map<int, FrameRecPos> CharSprites_JumpUp;
	//std::map<int, FrameRecPos> CharSprites_LightPunch;
	//std::map<int, FrameRecPos> CharSprites_MediumPunch;

	
	// Attributes
	Vector2 position;
	float speed;
	CharState currentState;

	// Animation data
	std::map<CharState, std::vector<AnimationFrame>> animations;
	size_t currentFrame;
	float frameCounter;
	float frameSpeed;
	std::string textureId; // ID for TexturesManager
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
//		
//	CharacterState* currentState;


};

#endif 

