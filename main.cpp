#include <iostream>
#include "Incident.h"
#include "UnlockedState.h"
#include "IncidentCoordinator.h"
#include "SecurityUnit.h"
#include "MedicUnit.h"
#include "FacilitiesUnit.h"
#include "AlertService.h"
#include "CampusArea.h"
#include "CampusUnit.h"
#include "AccessPoint.h"
#include "DoorController.h"
#include "LegacyDoorAccess.h"
#include "EmergencyFacade.h"
#include "DispatchSecurityCommand.h"
#include "DispatchMedicCommand.h"
#include "SecureZoneCommand.h"
#include "ActivateEmergencyCommand.h"

static void printScenario(const std::string& title, const std::string& patterns) {
    std::cout << std::endl << "[" << title << "]" << std::endl;
    std::cout << patterns << std::endl << std::endl;
}

int main() {
    IncidentCoordinator coordinator;

    SecurityUnit   security(&coordinator, "SecurityGuard-1");
    MedicUnit      medic(&coordinator, "Medic-1");
    FacilitiesUnit facilities(&coordinator, "Facilities-1");
    AlertService   alerts(&coordinator, "CampusAlertSystem");

    coordinator.registerUnit(&security);
    coordinator.registerUnit(&medic);
    coordinator.registerUnit(&facilities);
    coordinator.registerUnit(&alerts);

    printScenario("SCENARIO 1: Fire alarm, Engineering Building",
                  "Patterns: Facade, Command, Mediator, Composite, Adapter, State");

    DoorController engineeringDoor;
    LegacyDoorAccess engineeringAccess(&engineeringDoor);
    facilities.addAccessPoint(&engineeringAccess);

    CampusUnit* engineeringLab = new CampusUnit(new UnlockedState());
    CampusArea engineeringBuilding;
    engineeringBuilding.add(engineeringLab);

    Incident fireIncident(1, "Fire alarm triggered", "Engineering Building, Lab 4");
    std::cout << "Incident " << fireIncident.getID() << " reported at "
              << fireIncident.getLocation() << " -- status: "
              << fireIncident.getStatusName() << std::endl << std::endl;

    EmergencyFacade facade(fireIncident, engineeringBuilding);
    facade.declareEmergency(&security, &medic, &facilities, &alerts,
                             "Fire reported in Engineering Building, evacuate the area.");

    std::cout << std::endl << "Physical door bolted: "
              << (engineeringDoor.isBolted() ? "yes" : "no") << std::endl;
    std::cout << "Engineering building locked: "
              << (engineeringBuilding.isLocked() ? "yes" : "no") << std::endl;
    std::cout << "Incident status: " << fireIncident.getStatusName() << std::endl;

    printScenario("SCENARIO 2: Suspicious activity, Residence Block C",
                  "Patterns: Command (direct, no Facade), Mediator, Composite (multi-unit), "
                  "Adapter, State, handled invalid-operation case");

    DoorController blockCDoor1;
    DoorController blockCDoor2;
    LegacyDoorAccess blockCAccess1(&blockCDoor1);
    LegacyDoorAccess blockCAccess2(&blockCDoor2);
    facilities.addAccessPoint(&blockCAccess1);
    facilities.addAccessPoint(&blockCAccess2);

    CampusArea blockC;
    CampusUnit* roomC1 = new CampusUnit(new UnlockedState());
    CampusUnit* roomC2 = new CampusUnit(new UnlockedState());
    blockC.add(roomC1);
    blockC.add(roomC2);

    Incident suspiciousActivity(2, "Suspicious activity reported", "Residence Block C");
    std::cout << "Incident " << suspiciousActivity.getID() << " reported at "
              << suspiciousActivity.getLocation() << " -- status: "
              << suspiciousActivity.getStatusName() << std::endl;
    std::cout << "Block C locked before response: "
              << (blockC.isLocked() ? "yes" : "no") << std::endl << std::endl;

    DispatchSecurityCommand dispatchSecurity(&security, &blockC);
    dispatchSecurity.execute();

    SecureZoneCommand secureBlockC(&facilities, &blockC);
    secureBlockC.execute();

    ActivateEmergencyCommand alertResidents(&alerts,
        "Security responding to Residence Block C, please remain in your rooms.");
    alertResidents.execute();

    std::cout << std::endl << "Block C locked after response: "
              << (blockC.isLocked() ? "yes" : "no") << std::endl;
    std::cout << "Engineering door still bolted from Scenario 1: "
              << (engineeringDoor.isBolted() ? "yes" : "no") << std::endl;

    suspiciousActivity.transition();
    std::cout << "Incident status: " << suspiciousActivity.getStatusName() << std::endl;

    std::cout << std::endl << "Attempting to dispatch medic to a null destination..." << std::endl;
    CampusComponent* medicDestinationBefore = medic.getDestination();
    CampusComponent* nullDestination = nullptr;
    DispatchMedicCommand invalidDispatch(&medic, nullDestination);
    invalidDispatch.execute();
    if (medic.getDestination() == medicDestinationBefore) {
        std::cout << "Handled safely: null destination detected, medic's "
                  << "assignment left unchanged." << std::endl;
    }

    printScenario("SCENARIO 3: Escalation and System Stand Down",
                  "Hitting remaining state transitions, unlock procedures, and coordinator branches");

    // test to resolved state
    std::cout << "-- Testing Incident State Escalation --" << std::endl;
    suspiciousActivity.transition(); 
    suspiciousActivity.transition(); 

    // test to evacuation state
    std::cout << "\n-- Testing Zone State Escalation --" << std::endl;
    blockC.secure(); 
    blockC.secure(); 

    // test unlocking
    std::cout << "\n-- Testing Hardware and Logical Unlocking --" << std::endl;
    blockC.unlock();          
    blockCAccess1.unlock();   

    std::cout << "\n-- Testing Mediator Threat and Stand Down Broadcasts --" << std::endl;
    coordinator.respondToBuildingThreat();
    security.send("INCIDENT_RESOLVED"); 

    std::cout << "\n-- Testing Composite Memory Management --" << std::endl;
    blockC.remove(roomC1);
    roomC1->remove(nullptr);

    // roomC1 was taken out of blockC above, so blockC's destructor no
    // longer owns it - it's ours to clean up now, or it leaks
    delete roomC1;

    return 0;
}