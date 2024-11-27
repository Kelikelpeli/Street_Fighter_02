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
	l = KEY_LEFT;
	r = KEY_RIGHT;
	u = KEY_UP;
	d = KEY_DOWN;
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

void GameCharacter::SetControls(KeyboardKey left, KeyboardKey right, KeyboardKey up, KeyboardKey down)
{
	this->l=left;
	this->r = right;
	this->u = up;
	this->d = down;
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