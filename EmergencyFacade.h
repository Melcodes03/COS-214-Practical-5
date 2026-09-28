#ifndef EMERGENCYFACADE_H
#define EMERGENCYFACADE_H

#include <string>
#include "Incident.h"
#include "CampusComponent.h"
#include "SecurityUnit.h"
#include "MedicUnit.h"
#include "FacilitiesUnit.h"
#include "AlertService.h"

/*
 This is our Facade. Its whole job is to give one entry point that runs through dispatching securityfor the common case of "something bad happened, respond to it".
 */
class EmergencyFacade {
private:
    Incident& incident;
    CampusComponent& targetArea;

public:
    EmergencyFacade(Incident& incident, CampusComponent& targetArea);

    void declareEmergency(SecurityUnit* security, MedicUnit* medic,
                           FacilitiesUnit* facilities, AlertService* alert,
                           const std::string& alertMessage);
};

#endif