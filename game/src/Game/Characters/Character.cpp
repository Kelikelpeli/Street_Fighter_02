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

void GameCharacter::SetCharSpriteState(CharSpriteDirection newCharState)
{
	currentSpriteState = newCharState;
}



void GameCharacter::MoveCharacter()
{
	setPosition(getPosition().x+0.01f * getSpeed().x, getPosition().y+0.01 * getSpeed().y);
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

void GameCharacter::isJump(bool jump) {
	this->jump = jump;
}
bool GameCharacter::getJump() {
	return jump;
}

void GameCharacter::isCrouch(bool crouch) {
	this->crouch = crouch;
}

bool GameCharacter::getCrouch()
{
	return crouch;
}

void GameCharacter::setSpeed(float x, float y) {
	if (y > 0) {
		speed = Vector2{ x, y };
	}
	else {
		speed = Vector2{ x,getSpeed().y};
	}
}
Vector2 GameCharacter::getSpeed() {
	return speed;
}