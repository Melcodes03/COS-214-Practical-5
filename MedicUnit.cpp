#include "MedicUnit.h"
#include <iostream>

MedicUnit::MedicUnit(ResponseHub* hub, std::string name)
    : ResponseUnit(hub, name), destination(nullptr), dispatched(false) {}

MedicUnit::~MedicUnit() {}

void MedicUnit::dispatch(CampusComponent* destination) {
    this->destination = destination;
    dispatched = true;
    std::cout << "[" << getName() << "] dispatched to site." << std::endl;
    send("MEDIC_DISPATCHED");
}

CampusComponent* MedicUnit::getDestination() const {
    return destination;
}

void MedicUnit::receive(std::string event) {
    if (event == "STANDBY_REQUESTED") {
        std::cout << "[" << getName() << "] on standby, awaiting dispatch." << std::endl;
    } else if (event == "PREPARE_ACCESS") {
        std::cout << "[" << getName() << "] awaiting access at site." << std::endl;
    } else if (event == "STAND_DOWN") {
        dispatched = false;
        std::cout << "[" << getName() << "] standing down." << std::endl;
    } 
}
