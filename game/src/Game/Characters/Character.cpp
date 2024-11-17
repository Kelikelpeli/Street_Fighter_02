#include "Character.h"
#include <stdexcept>
#include "Game\Managers\TexturesManager.h"

//#include "Game/Managers/GameManager.h"
//#include "Game/States/CharacterState.h"

#include "raylib.h"

Character::Character(): position{ 0, 0 }, speed(0), currentState(CharState::Idle), currentFrame(0), frameCounter(0), frameSpeed(8.0f)
{
}

Character::~Character() {}


void Character::InitCharacter (const std::string& textureId)
{
    characterText = textureManager.GetTexture(textureId);
    //TexturesManager::GetInstance().LoadTexture(textureId);
}

void Character::UpdateCharacter(float deltaTime)
{
    UpdateAnimation(deltaTime);

    //// Update state machine
    //updateState();

    //// Update frame counter for animations
    //framesCounter++;
    //if (framesCounter >= (60 / framesSpeed))
    //{
    //    framesCounter = 0;
    //    currentFrame++;

    //    // TODO: Make this generic for every state, currently only valid for Idle state
    //    CharSpriteDirection currentStateDirection = static_cast<CharSpriteDirection>(currentState->getStateID());
    //    int totalNumFrames = CharSprites_Counter[currentStateDirection];
    //    if (currentFrame > totalNumFrames - 1)
    //    {
    //        currentFrame = 0;
    //    }
    
}

void Character::DrawCharacter()
{
    const auto& currentAnimation = animations[currentState];
    if (currentAnimation.empty()) return;

    const auto& frame = currentAnimation[currentFrame];
    characterText = textureManager.GetTexture(textureId);
   DrawTexturePro(texture, frame.frameRec, { position.x, position.y, frame.frameRec.width, frame.frameRec.height }, frame.origin, 0.0f, WHITE);
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
void Character::SetState(CharState state)
{
    if (currentState != state)
    {
        currentState = state;
        currentFrame = 0;
        frameCounter = 0;
    }

//currentState->exit(this);  // do something before we change state
	//currentState = &newState;  // change state
	//currentState->enter(this); // do something after we change state
	//framesCounter = 0;
}
CharState Character::GetState() const
{
    return currentState;
}

Rectangle Character::GetCollisionBox() const
{
    return { position.x, position.y, 50.0f, 50.0f }; // Example collision box
}

void Character::LoadAnimationFrames(CharState state, const std::vector<AnimationFrame>& frames)
{
    animations[state] = frames;
}

void Character::UpdateAnimation(float deltaTime)
{
    const auto& currentAnimation = animations[currentState];
    if (currentAnimation.empty()) return;

    frameCounter += deltaTime * frameSpeed;
    if (frameCounter >= 1.0f)
    {
        frameCounter = 0;
        currentFrame = (currentFrame + 1) % currentAnimation.size();
    }
}

//void Character::updateState()
//{
//    if (currentState)
//    {
//        currentState->updateState(this);
//    }
//	// Delegate the task of determining the next state to the current state!
//	//currentState->updateState(this);
//}