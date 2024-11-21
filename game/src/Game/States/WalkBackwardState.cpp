//#include "WalkBackwardState.h"
//#include "Game\Characters\Character.h"
//#include "CrouchState.h"
//#include "IdleState.h"
//
//WalkBackwardState& WalkBackwardState::getInstance() {
//    static WalkBackwardState instance;
//    return instance;
//}
//
//void WalkBackwardState::enter(Character* character) {
//    character->setStateAnimation(StateType::WalkBackward);
//}
//
//void WalkBackwardState::updateState(Character* character) {
//    if (IsKeyPressed(KEY_DOWN)) {
//        character->setState(CrouchState::getInstance());
//    }
//    else if (!IsKeyDown(KEY_LEFT)) {
//        character->setState(IdleState::getInstance());
//    }
//}
