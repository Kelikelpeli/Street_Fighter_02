#pragma once

#include "Game/Characters/Character.h"
#include "Game/Characters/Ken.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"
#include "Game/States/IdleState.h"
#include "Game/Managers/TexturesManager.h"

#include <string>             // String manipulation functions: strrchr(), strcmp()

#include "raylib.h"


void Ken::InitGameCharacter()
{
	//Let's fill the vector KenSprtes Data
	setPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
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
	CharSprites_WalkBackward[4] = FrameRecPos{ {1107,1878,225,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[5] = FrameRecPos{ {1367,1878,225,386}, {0.f, 0.f} };

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
	CharSprites_Counter[CharSpriteDirection::State_LightPunch] = 2;
	CharSprites_LightPunch[0] = FrameRecPos{ {4,4,260,386}, {0.f, 0.f} };
	CharSprites_LightPunch[1] = FrameRecPos{ {374,4,450,386}, {125.f, 0.f } };

	// MEDIUM PUNCH
	CharSprites_Counter[CharSpriteDirection::State_MediumPunch] = 3;

	CharSprites_MediumPunch[0] = FrameRecPos{ {4,390,322,382}, {0.f, 0.f} };
	CharSprites_MediumPunch[1] = FrameRecPos{ {328,390,317,382}, {0.f, 0.f} };
	CharSprites_MediumPunch[2] = FrameRecPos{ {652,390,508,382}, {170.f, 0.f} };

	CharSprites[CharSpriteDirection::State_Idle] = CharSprites_Idle;
	CharSprites[CharSpriteDirection::State_WalkForward] = CharSprites_WalkForward;
	CharSprites[CharSpriteDirection::State_WalkBackward] = CharSprites_WalkBackward;
	CharSprites[CharSpriteDirection::State_Crouch] = CharSprites_Crouch;
	CharSprites[CharSpriteDirection::State_JumpUp] = CharSprites_JumpUp;
	CharSprites[CharSpriteDirection::State_LightPunch] = CharSprites_LightPunch;
	CharSprites[CharSpriteDirection::State_MediumPunch] = CharSprites_MediumPunch;

	//init State
	currentState = &IdleState::getInstance();
	isJump(false);
	isCrouch(false);
	SetControls(KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN);
	setSpeed(3.0f, 3.0f);
}

void Ken::UpdateGameCharacter(float deltaTime) {

	//Update State Machine
	updateState();

	framesCounter++;

	if (framesCounter >= (60 / framesSpeed)) {

		framesCounter = 0;
		currentFrame++;

		//TODO make it generic for every state, this is only valid for Idle

		int totalNumFrames = CharSprites_Counter[currentSpriteState];
			if (currentFrame >= totalNumFrames ) {
				if (!getJump() && !getCrouch()) {
					currentFrame = 0;
				}
				else {
					 currentFrame = totalNumFrames - 1;
				}

			}
		

	}

	// add here the updateframe logic to be able to see all the sprites from one state
}

void Ken::DrawGameCharacter()
{
	TextureManager& textureManager = TextureManager::GetTextureManager();
	Texture2D kenSprites = textureManager.GetTexture(TextureType::BasicSpriteKen);
	//Texture2D kenSprites = LoadTexture("resources/Game/Sprites/Ken/KenBasicMovementsSprites.png");

	DrawTextureRec(kenSprites, CharSprites[currentSpriteState][currentFrame].frameRec, getPosition(), WHITE);

}

void Ken::UnloadGameCharacter()
{}

// State Machines
void Ken::setState(CharacterState& newState)
{
	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // change state
	currentState->enter(this); // do something after we change state
}

void Ken::updateState()
{
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);
}

