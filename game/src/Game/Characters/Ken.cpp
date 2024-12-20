#pragma once

#include "Game/Characters/Character.h"
#include "Game/Characters/Ken.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"
#include "Game/States/IdleState.h"
#include "Game/Managers/TexturesManager.h"

#include <string>             // String manipulation functions: strrchr(), strcmp()

#include "raylib.h"


void Ken::InitGameCharacter() {
	widthLimits = { 820,(float)GetScreenWidth() - 260 }; //Left limit at the car and right limit at the screen

	setPosition(GetScreenWidth() / 2.0f + 70, GetScreenHeight() / 2.0f + 100); //Initial position similar to the example screenshots

	//IDLE
	CharSprites_Counter[CharSpriteDirection::State_Idle] = 4;

	CharSprites_Idle[0] = FrameRecPos{ {4,4,260,386}, {0.f, 0.f} };
	CharSprites_Idle[1] = FrameRecPos{ {264,4,260,386}, {0.f, 0.f} };
	CharSprites_Idle[2] = FrameRecPos{ {524,4,260,386}, {0.f, 0.f} };
	CharSprites_Idle[3] = FrameRecPos{ {784,4,260,386}, {0.f, 0.f} };

	//WALK FORWARD
	CharSprites_Counter[CharSpriteDirection::State_WalkForward] = 5;

	CharSprites_WalkForward[0] = FrameRecPos{ {4,1493,260,386}, {0.f, 0.f} };
	CharSprites_WalkForward[1] = FrameRecPos{ {322,1493,260,386}, {0.f, 0.f} };
	CharSprites_WalkForward[2] = FrameRecPos{ {612,1493,260,386}, {0.f, 0.f} };
	CharSprites_WalkForward[3] = FrameRecPos{ {964,1493,260,386}, {0.f, 0.f} };
	CharSprites_WalkForward[4] = FrameRecPos{ {1237,1493,260,386}, {0.f, 0.f} };

	//WALK BACKWARDS
	CharSprites_Counter[CharSpriteDirection::State_WalkBackward] = 6;

	CharSprites_WalkBackward[0] = FrameRecPos{ {4,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[1] = FrameRecPos{ {264,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[2] = FrameRecPos{ {524,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[3] = FrameRecPos{ {783,1878,321,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[4] = FrameRecPos{ {1107,1878,280,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[5] = FrameRecPos{ {1367,1878,280,386}, {0.f, 0.f} };

	// JUMP UP
	CharSprites_Counter[CharSpriteDirection::State_JumpUp] = 6;

	CharSprites_JumpUp[0] = FrameRecPos{ {4,2718,260,446}, {0.f, 0.f} };
	CharSprites_JumpUp[1] = FrameRecPos{ {264,2718,260,446}, {0.f, 0.f} };
	CharSprites_JumpUp[2] = FrameRecPos{ {524,2718,260,384}, {0.f, 0.f} };
	CharSprites_JumpUp[3] = FrameRecPos{ {784,2718,260,384}, {0.f, 0.f} };
	CharSprites_JumpUp[4] = FrameRecPos{ {1044,2718,260,384}, {0.f, 0.f} };
	CharSprites_JumpUp[5] = FrameRecPos{ {1304,2718,260,446}, {0.f, 0.f} };

	// CROUCH
	CharSprites_Counter[CharSpriteDirection::State_Crouch] = 3;

	CharSprites_Crouch[0] = FrameRecPos{ {4,842,260,386}, {0.f, 0.f} };
	CharSprites_Crouch[1] = FrameRecPos{ {264,842,321,386}, {0.f, 0.f} };
	CharSprites_Crouch[2] = FrameRecPos{ {586,842,320,386}, {0.f, 0.f} };

	// LIGHT PUNCH
	CharSprites_Counter[CharSpriteDirection::State_Special1] = 2;
	CharSprites_Special1[0] = FrameRecPos{ {4,4,260,386}, {0.f, 0.f} };
	CharSprites_Special1[1] = FrameRecPos{ {374,4,450,386}, {125.f, 0.f } };

	// MEDIUM PUNCH
	CharSprites_Counter[CharSpriteDirection::State_Special2] = 3;

	CharSprites_Special2[0] = FrameRecPos{ {4,390,322,382}, {0.f, 0.f} };
	CharSprites_Special2[1] = FrameRecPos{ {328,390,317,382}, {0.f, 0.f} };
	CharSprites_Special2[2] = FrameRecPos{ {652,390,508,382}, {170.f, 0.f} };

	CharSprites[CharSpriteDirection::State_Idle] = CharSprites_Idle;
	CharSprites[CharSpriteDirection::State_WalkForward] = CharSprites_WalkForward;
	CharSprites[CharSpriteDirection::State_WalkBackward] = CharSprites_WalkBackward;
	CharSprites[CharSpriteDirection::State_Crouch] = CharSprites_Crouch;
	CharSprites[CharSpriteDirection::State_JumpUp] = CharSprites_JumpUp;
	CharSprites[CharSpriteDirection::State_Special1] = CharSprites_Special1;
	CharSprites[CharSpriteDirection::State_Special2] = CharSprites_Special2;

	//init State
	currentState = &IdleState::getInstance();
	isStop(false);
	setSpeed(6.0f, 3.0f);
	setAttack(false);

	bodyColliderRect = { getPosition().x + 50, getPosition().y + 20, 170, 350 }; // body collider
	hitColliderRect = { getPosition().x - 125.f, getPosition().y + 80, 80, 30 }; // punch collider
}

void Ken::UpdateGameCharacter(float deltaTime) {

	//Update State Machine
	updateState();

	//Update colliders
	bodyColliderRect = { getPosition().x + 50, getPosition().y + 20, 170, 350 }; 
	hitColliderRect = { getPosition().x - 125.f, getPosition().y + 80, 80, 30 }; 
	framesCounter++;

	if (framesCounter >= (60 / framesSpeed)) {
		framesCounter = 0;
		currentFrame++;

		//Generic for all states
		int totalNumFrames = CharSprites_Counter[currentSpriteState];
		if (currentFrame >= totalNumFrames) {
			if (!stop) {
				currentFrame = 0;
			} else {
				currentFrame = totalNumFrames - 1;
			}
		}
	}
}

void Ken::DrawGameCharacter()
{
	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D kenSprites = textureManager.GetTexture(TextureType::BasicSpriteKen);
	Texture2D punchText = textureManager.GetTexture(TextureType::PunchSpriteKen);

	//If not attacking, use basic texture; otherwise, use attack texture
	if (currentSpriteState != CharSpriteDirection::State_Special1 && currentSpriteState != CharSpriteDirection::State_Special2) {
		DrawTextureRec(kenSprites, CharSprites[currentSpriteState][currentFrame].frameRec,
			Vector2{ getPosition().x - CharSprites[currentSpriteState][currentFrame].frameOrigin.x,
			getPosition().y - -CharSprites[currentSpriteState][currentFrame].frameOrigin.y }, WHITE);

	} else {
		DrawTextureRec(punchText, CharSprites[currentSpriteState][currentFrame].frameRec,
			Vector2{ getPosition().x - CharSprites[currentSpriteState][currentFrame].frameOrigin.x,
			getPosition().y - -CharSprites[currentSpriteState][currentFrame].frameOrigin.y }, WHITE);
	}
}

void Ken::UnloadGameCharacter(){}

// State Machines
void Ken::setState(CharacterState& newState) {
	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // change state
	currentState->enter(this); // do something after we change state
}

Rectangle Ken::getHitColliderRect() {
	return hitColliderRect;
}

void Ken::updateState()
{
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);
}

