#include "LegacyDoorAccess.h"
#include "DoorController.h"

LegacyDoorAccess::LegacyDoorAccess(DoorController* controller) : controller(controller) {}

LegacyDoorAccess::~LegacyDoorAccess() {}

void LegacyDoorAccess::lock() {
    if (controller != nullptr) {
        controller->engageBolt();
    }
}

void LegacyDoorAccess::unlock() {
    if (controller != nullptr) {
        controller->releaseBolt();
    }
}

bool LegacyDoorAccess::isLocked() {
    return controller != nullptr && controller->isBolted();
}