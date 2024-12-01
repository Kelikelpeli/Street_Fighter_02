#include "Character.h"

#include "Game/Managers/GameManager.h"
#include "Game/States/CharacterState.h"
#include "Game/GlobalGameDefines.h"

#include "raylib.h"

GameCharacter::GameCharacter() {}

void GameCharacter::InitGameCharacter() {
	currentFrame = 0;
	framesCounter = 0;

	framesSpeed = 8;
}

void GameCharacter::UpdateGameCharacter(float deltaTime) {}

void GameCharacter::DrawGameCharacter() {}

void GameCharacter::UnloadGameCharacter() {}

// State Machines
void GameCharacter::setState(CharacterState& newState) {
	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // change state
	currentState->enter(this); // do something after we change state
	framesCounter = 0;
}

void GameCharacter::SetCharSpriteState(CharSpriteDirection newCharState) {
	currentSpriteState = newCharState;
}

void GameCharacter::updateState() {
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);

}

// Ensure the character stays within screen/car boundaries
void GameCharacter::setPosition(float x, float y) {
	if (x >= widthLimits.x && x <= widthLimits.y) {
		position.x = x;
	}
	position.y = y;
}

Vector2 GameCharacter::getPosition() {
	return position;
}

// For animations without looping
void GameCharacter::isStop(bool stop) {
	this->stop = stop;
}

bool GameCharacter::getStop() {
	return stop;
}

Rectangle GameCharacter::getBodyColliderRect() {
	return bodyColliderRect;
}

void GameCharacter::setSpeed(float x, float y) {
	if (y > 0) {
		speed = Vector2{ x, y };
	}
	else {
		speed = Vector2{ x,getSpeed().y };
	}
}

Vector2 GameCharacter::getSpeed() {
	return speed;
}

// For collisions and damage
void GameCharacter::setAttack(bool attack) {
	this->attack = attack;
}

bool GameCharacter::GetAttack() {
	return attack;
}