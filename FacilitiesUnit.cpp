#include "FacilitiesUnit.h"
#include <iostream>

FacilitiesUnit::FacilitiesUnit(ResponseHub* hub, std::string name)
    : ResponseUnit(hub, name), accessRestricted(false) {}

FacilitiesUnit::~FacilitiesUnit() {}

void FacilitiesUnit::addAccessPoint(AccessPoint* ap) {
    if (ap != nullptr) {
        accessPoints.push_back(ap);
    }
}

void FacilitiesUnit::secureArea(CampusComponent* area) {
    for (AccessPoint* door : accessPoints) {
        door->lock();
    }
    
    if (area != nullptr) {
        area->secure();
    }
    
    accessRestricted = true;
    std::cout << "[" << getName() << "] area physically and logically secured." << std::endl;
    send("AREA_SECURED"); 
}

void FacilitiesUnit::receive(std::string event) {
    if (event == "PREPARE_ACCESS") {
        std::cout << "[" << getName() << "] preparing access points for responders." << std::endl;
    } else if (event == "STAND_DOWN") {
        accessRestricted = false;
        std::cout << "[" << getName() << "] restoring normal access." << std::endl;
    }
}