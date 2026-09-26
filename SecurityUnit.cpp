#include "SecurityUnit.h"
#include <iostream>

SecurityUnit::SecurityUnit(ResponseHub* hub, std::string name)
    : ResponseUnit(hub, name), destination(nullptr), onStandby(false) {}

SecurityUnit::~SecurityUnit() {}

void SecurityUnit::dispatch(CampusComponent* destination) {
    this->destination = destination;
    std::cout << "[" << getName() << "] dispatched to site." << std::endl;
    send("SECURITY_DISPATCHED");
}

CampusComponent* SecurityUnit::getDestination() const {
    return destination;
}

void SecurityUnit::receive(std::string event) {
    if (event == "STANDBY_REQUESTED") {
        onStandby = true;
        std::cout << "[" << getName() << "] moving to standby." << std::endl;
    } else if (event == "STAND_DOWN") {
        onStandby = false;
        std::cout << "[" << getName() << "] standing down." << std::endl;
    } else {
        std::cout << "[" << getName() << "] received unhandled event: " << event << std::endl;
    }
}
