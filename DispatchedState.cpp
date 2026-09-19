#include "DispatchedState.h"
#include "ResolvedState.h"
#include "Incident.h"
#include <iostream>

void DispatchedState::handle(Incident& incident) {
    // once a dispatched incident is handled again we treat it as resolved
    std::cout << "Incident " << incident.getID()<< " units have been dispatched, marking as resolved" << std::endl;

    incident.setState(new ResolvedState());
}

std::string DispatchedState::getStatusName() const {
    return "Dispatched";
}