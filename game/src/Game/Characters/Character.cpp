#include "Character.h"
//#include <stdexcept>
#include "Game\Managers\TexturesManager.h"
#include "Game\States\IdleState.h"

//#include "Game/Managers/GameManager.h"
//#include "Game/States/CharacterState.h"

#include "raylib.h"

Character::Character(): position{ 0, 0 }, speed(0), currentState(nullptr), currentFrame(0), frameCounter(0), frameSpeed(6.0f) {}
Character::~Character() {}


void Character::InitCharacter ()
{
   
}

void Character::UpdateCharacter(float deltaTime)
{
  //  UpdateAnimation(deltaTime);

    if (!currentState) return;

    // Update animation frames
    frameCounter += deltaTime * frameSpeed;
    if (frameCounter >= 1.0f) {
        frameCounter = 0;

        StateType state = currentState->getStateType();
        const auto& currentAnimation = animations[state];
        currentFrame = (currentFrame + 1) % currentAnimation.size();
    }
    
}

void Character::DrawCharacter()
    {
      /*  const auto & currentAnimation = animations[currentState];
        if (currentAnimation.empty()) return;

        const auto& frame = currentAnimation[currentFrame];
        textureManager.DrawTextureOriginRec(characterText, CharSprites_Idle[currentFrame].frameRec, GetPosition(), WHITE, Vector2{(float)CharSprites_Crouch[2].frameRec.width / 2, (float)CharSprites_Crouch[2].frameRec.height / 2});*/

    if (!currentState) return;

    StateType state = currentState->getStateType();
    const auto& currentAnimation = animations[state];
    if (currentAnimation.empty()) return;

    const auto& frame = currentAnimation[currentFrame];
    DrawTextureRec(characterText, frame.frameRec, position, WHITE);
}

void Character::SetPosition(Vector2 pos)
{
    position = pos;
}

Vector2 Character::GetPosition() const
{
    return position;
}

void Character::SetSpeed(float spd)
{
    speed = spd;
}

float Character::GetSpeed() const
{
    return speed;
}

// State Machines
void Character::setState(CharacterState& newState) {
    if (currentState) {
        currentState->exit(this);  // Use -> because currentState is a pointer
    }
    currentState = &newState;      // Assign the address of newState
    currentState->enter(this);     // Use -> to call enter
    frameCounter = 0;             // Reset frame counter
}

void Character::updateState() {
    if (currentState) {
        currentState->updateState(this); // Use -> to delegate the update
    }
}

Rectangle Character::GetCollisionBox() const
{
    return { position.x, position.y, 50.0f, 50.0f }; // Example collision box
}

void Character::LoadAnimationFrames(StateType state, const std::vector<AnimationFrame>& frames)
{
    animations[state] = frames;
}

//void Character::UpdateAnimation(float deltaTime)
//{
//    const auto& currentAnimation = animations[StateType];
//    if (currentAnimation.empty()) return;
//
//    frameCounter += deltaTime * frameSpeed;
//    if (frameCounter >= 1.0f)
//    {
//        frameCounter = 0;
//        currentFrame = (currentFrame + 1) % currentAnimation.size();
//    }
//}

//void Character::updateState()
//{
//    if (currentState)
//    {
//        currentState->updateState(this);
//    }
//	// Delegate the task of determining the next state to the current state!
//	//currentState->updateState(this);
//}