#include "DoorController.h"
#include <iostream>

DoorController::DoorController() : bolted(false) {}

void DoorController::engageBolt() {
    bolted = true;
    std::cout << "[DoorController] bolt engaged." << std::endl;
}

void DoorController::releaseBolt() {
    bolted = false;
    std::cout << "[DoorController] bolt released." << std::endl;
}

bool DoorController::isBolted() const {
    return bolted;
}
