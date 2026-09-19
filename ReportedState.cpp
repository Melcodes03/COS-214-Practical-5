#include "ReportedState.h"
#include "DispatchedState.h"
#include "Incident.h"
#include <iostream>

void ReportedState::handle(Incident& incident) {
    // calling transition on a reported incident means units are now being sent
    std::cout << "Incident " << incident.getID()<< " has been reported, moving to dispatched" << std::endl;

    incident.setState(new DispatchedState());
}

std::string ReportedState::getStatusName() const {
    return "Reported";
}