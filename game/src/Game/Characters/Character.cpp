#include "Character.h"

#include "Game/Managers/GameManager.h"
#include "Game/States/CharacterState.h"

#include "raylib.h"

GameCharacter::GameCharacter()
{
}

void GameCharacter::InitGameCharacter()
{
	//ken.InitGameCharacter();
	currentFrame = 0;

	framesCounter = 0;
	framesSpeed = 8;
}

void GameCharacter::UpdateGameCharacter(float deltaTime)
{

}

void GameCharacter::DrawGameCharacter()
{
}

void GameCharacter::UnloadGameCharacter()
{

}


// State Machines
void GameCharacter::setState(CharacterState& newState)
{
	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // change state
	currentState->enter(this); // do something after we change state
	framesCounter = 0;

}

void GameCharacter::updateState()
{
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);
}
void GameCharacter::setPosition(float x, float y) {
	position = Vector2{ x, y };
}
Vector2 GameCharacter::getPosition() {
	return position;
}