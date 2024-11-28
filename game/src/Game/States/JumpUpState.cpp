
#include "IdleState.h"
#include "WalkForwardState.h"
#include "WalkBackwardState.h"
#include "CrouchState.h"
#include "JumpUpState.h"
#include "Special1State.h"
#include "Special2State.h"


void JumpUpState::enter(GameCharacter* character){
	character->SetCharSpriteState(CharSpriteDirection::State_JumpUp);
	character->isStop(true); // Marca el personaje como saltando
	startTime = GetTime();   // Registra el tiempo de inicio del salto
}


void JumpUpState::updateState(GameCharacter* character) {
	const float jumpDuration = 2.0f;    // Duraci�n total del salto (en segundos)
	const float jumpHeight = 450.0f;   // Altura m�xima del salto
	const float gravity = 300.0f;      // Velocidad de ca�da controlada
	float elapsedTime = GetTime() - startTime; // Tiempo transcurrido desde el inicio del salto
	if (elapsedTime < jumpDuration / 2) {
		// Fase de subida
		character->setPosition(character->getPosition().x, character->getPosition().y - jumpHeight * GetFrameTime());
	}
	else if (elapsedTime < jumpDuration) {
		// Fase de bajada
		character->setPosition(character->getPosition().x, character->getPosition().y + gravity * GetFrameTime());
	}
	else {
		// Finaliza el salto y regresa a Idle
		character->setPosition(character->getPosition().x, character->groundLevel); // Ajusta la posici�n al suelo
		character->isStop(false); // Marca que el personaje ya no est� saltando
		character->setState(IdleState::getInstance());
	}
	/*if (IsKeyPressed(KEY_LEFT)){

		character->setState(WalkForwardState::getInstance());

	}else if (IsKeyPressed(KEY_RIGHT)){

		character->setState(WalkBackwardState::getInstance());

	}*/
	//if (character->getPosition().y <= 100) { // Altura m�xima
	//	character->setSpeed(character->getSpeed().x, -character->getSpeed().y); // Cambia direcci�n a caer
	//}
	//else if (character->getPosition().y >= 400) { // Regresa al suelo
	//	character->setPosition(character->getPosition().x, 400); // Ajusta posici�n al suelo
	//	character->setState(IdleState::getInstance()); // Cambia a Idle
	//}

	// Add more states

}


CharacterState& JumpUpState::getInstance(){

	static JumpUpState singleton;

	return singleton;

}