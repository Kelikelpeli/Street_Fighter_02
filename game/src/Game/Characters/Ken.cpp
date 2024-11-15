#pragma once

#include "Game/Characters/Character.h"
#include "Game/Characters/Ken.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"
#include "Game/Managers/TexturesManager.h"

#include "Game/States/IdleState.h"
#include "Game/States/CrouchState.h"
#include "Game/States/WalkForwardState.h"
#include "Game/States/WalkBackwardState.h"
#include "Game/States/JumpUpState.h"


#include <string>             // String manipulation functions: strrchr(), strcmp()

#include "raylib.h"



void Ken::InitCharacter()
{

	//Let's fill the vector KenSprtes Data
	
	//IDLE
	CharSprites_Counter[CharSpriteDirection::State_Idle] = 4;

	CharSprites_Idle[0] = FrameRecPos{ {4,4,260,386}, {0.f, 0.f} };
	CharSprites_Idle[1] = FrameRecPos{ {264,4,260,386}, {0.f, 0.f}};
	CharSprites_Idle[2] = FrameRecPos{ {524,4,260,386}, {0.f, 0.f}};
	CharSprites_Idle[3] = FrameRecPos{ {784,4,260,386}, {0.f, 0.f}};
	
	//WALK FORWARD
	CharSprites_Counter[CharSpriteDirection::State_WalkForward] = 5;

	CharSprites_WalkForward[0] = FrameRecPos{ {4,1493,260,386}, {0.f, 0.f} };
	CharSprites_WalkForward[1] = FrameRecPos{ {322,1493,260,386}, {0.f, 0.f}};
	CharSprites_WalkForward[2] = FrameRecPos{ {612,1493,260,386}, {0.f, 0.f}};
	CharSprites_WalkForward[3] = FrameRecPos{ {964,1493,260,386}, {0.f, 0.f}};
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

	//init State
	currentState = &IdleState::getInstance();

}

void Ken::UpdateCharacter(float deltaTime)
{

	//Update State Machine
	updateState();

    // add here the updateframe logic to be able to see all the sprites from one state
}

void Ken::DrawCharacter()
{
	TextureManager& textureManager = TextureManager::GetTextureManager();

	setPosition(Vector2 { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
	Texture2D Kentext2DSprites = LoadTexture("resources/UI/MarioLifesIcon.png");// textureManager.GetTexture(TextureType::BasicSpriteKen);
	//DrawTexture(Kentext2DSprites, GetScreenHeight() / 2.0f, GetScreenHeight() / 2.0f, WHITE);
	////DrawTextureRec(Kentext2DSprites, CharSprites_Idle[0].frameRec, Vector2{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, WHITE);

	currentFrame = 0; // Inicializa a 0 para asegurarte de que apunta al primer frame

	if(Kentext2DSprites.id > 0) {
		DrawTextureRec(Kentext2DSprites, CharSprites_Idle[currentFrame].frameRec, getPosition(), WHITE);
	}
	else {
		DrawText("Error: Ken texture not loaded", 10, 10, 20, RED);
		}
//	DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 20, 20, RED);
}

void Ken::UnloadCharacter()
{

}

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

