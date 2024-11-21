//#include "CrouchState.h"
//#include "Game\Characters\Character.h"
//#include "IdleState.h"
//
//CrouchState& CrouchState::getInstance() {
//    static CrouchState instance;
//    return instance;
//}
//
//void CrouchState::enter(Character* character) {
//    character->setStateAnimation(StateType::Crouch);
//}
//
//void CrouchState::updateState(Character* character) {
//    if (!IsKeyDown(KEY_DOWN)) {
//        character->setState(IdleState::getInstance());
//    }
//}
