#include "Incident.h"
#include <iostream>

// just a quick manual test to check the state transitions actually work
// before this gets wired up with the other patterns

int main() {
    Incident incident(1, "Fire alarm triggered", "Engineering Building");

    std::cout << "Incident created, status: " << incident.getStatusName() << std::endl;

    incident.transition();
    std::cout << "After 1st transition, status: " << incident.getStatusName() << std::endl;

    incident.transition();
    std::cout << "After 2nd transition, status: " << incident.getStatusName() << std::endl;

    // calling it again once resolved should just say theres nothing more to do
    incident.transition();
    std::cout << "After 3rd transition, status: " << incident.getStatusName() << std::endl;

    return 0;
}