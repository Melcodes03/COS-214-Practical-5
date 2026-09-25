#include "EvacuationState.h"
#include "CampusUnit.h"
#include <iostream>

void EvacuationState::handle(CampusUnit& unit) {
    // nothing further to do once evacuation has been triggered
    std::cout << "Unit is already in evacuation mode, nothing more to do" << std::endl;
}

std::string EvacuationState::getStatusName() const {
    return "Evacuation";
}