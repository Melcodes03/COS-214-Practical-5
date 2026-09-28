#include "EmergencyFacade.h"
#include "DispatchSecurityCommand.h"
#include "DispatchMedicCommand.h"
#include "SecureZoneCommand.h"
#include "ActivateEmergencyCommand.h"
#include <iostream>

EmergencyFacade::EmergencyFacade(Incident& incident, CampusComponent& targetArea)
    : incident(incident), targetArea(targetArea) {}

void EmergencyFacade::declareEmergency(SecurityUnit* security, MedicUnit* medic,
                                        FacilitiesUnit* facilities, AlertService* alert,
                                        const std::string& alertMessage) {
    std::cout << "[EmergencyFacade] declaring emergency for incident "
              << incident.getID() << " (" << incident.getDescription() << ")" << std::endl;

    // dispatching a unit is just building the command and running it,
    // the facade doesnt care what actually happens inside execute()
    DispatchSecurityCommand dispatchSecurity(security, &targetArea);
    dispatchSecurity.execute();

    DispatchMedicCommand dispatchMedic(medic, &targetArea);
    dispatchMedic.execute();

    // facilities is the one who actually secures the area, and the area
    // itself is a composite so this works the same for a room or a building
    SecureZoneCommand secure(facilities, &targetArea);
    secure.execute();

    // let campus know whats going on
    ActivateEmergencyCommand raiseAlert(alert, alertMessage);
    raiseAlert.execute();

    // finally move the incident itself along in its own lifecycle
    incident.transition();

    std::cout << "[EmergencyFacade] incident " << incident.getID()
              << " is now " << incident.getStatusName() << std::endl;
}