
#include "IdleState.h"
#include "WalkForwardState.h"
#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"


void JumpUpState::enter(GameCharacter* character){
	character->SetCharSpriteState(CharSpriteDirection::State_JumpUp);

}


void JumpUpState::updateState(GameCharacter* character) {

	/*if (IsKeyPressed(KEY_LEFT)){

		character->setState(WalkForwardState::getInstance());

	}else if (IsKeyPressed(KEY_RIGHT)){

		character->setState(WalkBackwardState::getInstance());

	}*/
	if (character->getPosition().y <= 100) { // Altura máxima
		character->setSpeed(character->getSpeed().x, -character->getSpeed().y); // Cambia dirección a caer
	}
	else if (character->getPosition().y >= 400) { // Regresa al suelo
		character->setPosition(character->getPosition().x, 400); // Ajusta posición al suelo
		character->setState(IdleState::getInstance()); // Cambia a Idle
	}

	// Add more states

}


CharacterState& JumpUpState::getInstance(){

	static JumpUpState singleton;

	return singleton;

}