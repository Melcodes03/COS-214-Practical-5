#include "AlertService.h"
#include <iostream>

AlertService::AlertService(ResponseHub* hub, std::string name) : ResponseUnit(hub, name) {}

AlertService::~AlertService() {}

void AlertService::broadcast(std::string message) {
    std::cout << "[" << getName() << "] campus-wide alert: " << message << std::endl;
}

void AlertService::receive(std::string event) {
    if (event == "STANDBY_REQUESTED") {
        broadcast("Security incident reported. Please remain alert.");
    } else if (event == "AREA_SECURED_ACK") {
        broadcast("Affected area has been secured.");
    } else if (event == "STAND_DOWN") {
        broadcast("Incident resolved. Normal operations resumed.");
    } else {
        std::cout << "[" << getName() << "] received unhandled event: " << event << std::endl;
    }
}
