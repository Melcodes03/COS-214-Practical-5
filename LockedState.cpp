#include "LockedState.h"
#include "EvacuationState.h"
#include "CampusUnit.h"
#include <iostream>

void LockedState::handle(CampusUnit& unit) {
    // once a locked unit is handled again, an emergency has escalated
    // things far enough that doors get forced open for evacuation
    std::cout << "Unit is locked, forcing unlock for evacuation" << std::endl;

    unit.transition(new EvacuationState());
}

std::string LockedState::getStatusName() const {
    return "Locked";
}