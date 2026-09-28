#include "IncidentCoordinator.h"
#include "ResponseUnit.h"
#include <algorithm>
#include <iostream>

IncidentCoordinator::IncidentCoordinator() : incidentStatus("IDLE") {}

IncidentCoordinator::~IncidentCoordinator() {}

void IncidentCoordinator::registerUnit(ResponseUnit* unit) {
    if (unit == nullptr) {
        return;
    }
    if (std::find(units.begin(), units.end(), unit) == units.end()) {
        units.push_back(unit);
    }
}

void IncidentCoordinator::broadcastExcept(std::string event, ResponseUnit* sender) {
    for (ResponseUnit* unit : units) {
        if (unit != sender) {
            unit->receive(event);
        }
    }
}

void IncidentCoordinator::notify(std::string event, ResponseUnit* sender) {
    if (event == "THREAT_CONFIRMED") {
        incidentStatus = "ACTIVE";
        broadcastExcept("STANDBY_REQUESTED", sender);
    } else if (event == "SECURITY_DISPATCHED") {
        incidentStatus = "ACTIVE";
        broadcastExcept("PREPARE_ACCESS", sender);
    } else if (event == "MEDIC_DISPATCHED") {
        broadcastExcept("PREPARE_ACCESS", sender);
    } else if (event == "AREA_SECURED") {
        incidentStatus = "CONTAINED";
        broadcastExcept("AREA_SECURED_ACK", sender);
    } else if (event == "INCIDENT_RESOLVED") {
        incidentStatus = "RESOLVED";
        broadcastExcept("STAND_DOWN", sender);
    } else {
        broadcastExcept(event, sender);
    }

    std::cout << "[IncidentCoordinator] status is now " << incidentStatus
              << " after event \"" << event << "\" from "
              << (sender != nullptr ? sender->getName() : "unknown") << std::endl;
}

std::string IncidentCoordinator::getIncidentStatus() const {
    return incidentStatus;
}

void IncidentCoordinator::dispatchUnit(ResponseUnit* unit, std::string location) {
    if (unit != nullptr) {
        dispatchLog[unit] = location;
        std::cout << "[IncidentCoordinator] Central dispatch sending " 
                  << unit->getName() << " to " << location << "." << std::endl;
    }
}

std::string IncidentCoordinator::locationOf(ResponseUnit* unit) {
    auto it = dispatchLog.find(unit);
    if (it != dispatchLog.end()) {
        return it->second;
    }
    return "Location Unknown / Standby";
}

void IncidentCoordinator::respondToBuildingThreat() {
    incidentStatus = "ACTIVE_THREAT";
    std::cout << "[IncidentCoordinator] THREAT DETECTED. Triggering response protocols." << std::endl;
    
    for (ResponseUnit* unit : units) {
        unit->receive("THREAT_CONFIRMED");
    }
}
