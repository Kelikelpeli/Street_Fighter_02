#include "Character.h"

#include "Game/Managers/GameManager.h"
#include "Game/States/CharacterState.h"

#include "raylib.h"

Character::Character() : currentState(nullptr), position({ 0.0f, 0.0f }), speed({ 0.0f, 0.0f }), collisionBox({ 0.0f, 0.0f, 50.0f, 50.0f }) {}



void Character::InitCharacter ()
{
	currentFrame = 0;

	framesCounter = 0;
	framesSpeed = 8;

    position = { 0.0f, 0.0f };
    speed = { 0.0f, 0.0f };

}

void Character::UpdateCharacter(float deltaTime)
{
    // Update state machine
    updateState();

    // Update frame counter for animations
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        // TODO: Make this generic for every state, currently only valid for Idle state
        CharSpriteDirection currentStateDirection = static_cast<CharSpriteDirection>(currentState->getStateID());
        int totalNumFrames = CharSprites_Counter[currentStateDirection];
        if (currentFrame > totalNumFrames - 1)
        {
            currentFrame = 0;
        }
    }

    // Update position based on speed
    position.x += speed.x * deltaTime;
    position.y += speed.y * deltaTime; 

    // Update collision box position
    collisionBox.x = position.x;
    collisionBox.y = position.y;
}

void Character::DrawCharacter()
{
}

void Character::UnloadCharacter()
{

}

bool Character::checkCollision(const Rectangle& other) const
{
    return CheckCollisionRecs(collisionBox, other);
}


void Character::applyMovementLimits(Rectangle bounds)
{
    if (position.x < bounds.x) position.x = bounds.x;
    if (position.x + collisionBox.width > bounds.x + bounds.width) position.x = bounds.x + bounds.width - collisionBox.width;
    if (position.y < bounds.y) position.y = bounds.y;
    if (position.y + collisionBox.height > bounds.y + bounds.height) position.y = bounds.y + bounds.height - collisionBox.height;
}

bool Character::isWithinBounds(Rectangle bounds) const
{
    return (position.x >= bounds.x && position.x + collisionBox.width <= bounds.x + bounds.width &&
        position.y >= bounds.y && position.y + collisionBox.height <= bounds.y + bounds.height);
}

// State Machines
void Character::setState(CharacterState& newState)
{
    if (currentState)
    {
        currentState->exit(this);  // Exit the current state before transitioning
    }
    currentState = &newState;
    currentState->enter(this); // Enter the new state
    resetFrameCounter();

	//currentState->exit(this);  // do something before we change state
	//currentState = &newState;  // change state
	//currentState->enter(this); // do something after we change state
	//framesCounter = 0;
}

void Character::updateState()
{
    if (currentState)
    {
        currentState->updateState(this);
    }
	// Delegate the task of determining the next state to the current state!
	//currentState->updateState(this);
}