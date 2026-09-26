#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

void ResolvedState::handle(Incident& incident) {
    // nothing really happens after this, incident is already closed
    std::cout << "Incident " << incident.getID()<< " is already resolved, nothing more to do" << std::endl;
}

std::string ResolvedState::getStatusName() const {
    return "Resolved";
}