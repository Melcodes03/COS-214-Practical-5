#include "UnlockedState.h"
#include "LockedState.h"
#include "CampusUnit.h"
#include <iostream>

void UnlockedState::handle(CampusUnit& unit) {
    // calling transition on an unlocked unit means a secure command
    // has come in, so it moves to locked
    std::cout << "Unit is unlocked, securing and moving to locked" << std::endl;

    unit.transition(new LockedState());
}

std::string UnlockedState::getStatusName() const {
    return "Unlocked";
}