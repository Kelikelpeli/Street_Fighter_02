#include "Character.h"

#include "Game/Managers/GameManager.h"
#include "Game/States/CharacterState.h"
#include "Game/GlobalGameDefines.h"

#include <iostream>


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
	left = KEY_LEFT;
	right = KEY_RIGHT;
	up = KEY_UP;
	down = KEY_DOWN;
	special1 = KEY_Q;
	special2 = KEY_T;
	//widthLimits = { 0,1920};
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

void GameCharacter::updateState()
{
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);
	
}
void GameCharacter::setPosition(float x, float y) {
	std::cout << "Limites de ancho: " << widthLimits.x << " - " << widthLimits.y << std::endl;
	if (x >= widthLimits.x && x <= widthLimits.y) {
		position.x = x;
	}
	position.y = y;

}
Vector2 GameCharacter::getPosition() {
	return position;
}

void GameCharacter::isStop(bool stop) {
	this->stop = stop;
}
bool GameCharacter::getStop() {
	return stop;
}




Rectangle GameCharacter::getBodyColliderRect()
{
	return bodyColliderRect;
}


void GameCharacter::SetControls(KeyboardKey left, KeyboardKey right, KeyboardKey up, KeyboardKey down, KeyboardKey special1, KeyboardKey special2)
{
	this->left=left;
	this->right = right;
	this->up = up;
	this->down = down;
	this->special1 = special1;
	this->special2 = special2;
}

KeyboardKey GameCharacter::GetControl(char control)
{
	/*switch (control) {
	case l:
			return l;
			break;	
	case Controls::right:
		return r;
		break;
	case Controls::down:
		return d;
		break;
	case Controls::up:
		return u;
		break;
	}*/
	return KeyboardKey();
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
void GameCharacter::setAttack(bool attack)
{
	this->attack = attack;
}

bool GameCharacter::GetAttack()
{
	return attack;
}