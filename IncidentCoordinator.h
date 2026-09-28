#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include <string>
#include <vector>
#include <map>
#include "ResponseHub.h"
#include "ResponseUnit.h"

class IncidentCoordinator : public ResponseHub {
private:
    std::vector<ResponseUnit*> units;
    std::map<ResponseUnit*, std::string> dispatchLog; 
    std::string incidentStatus;
    
    void broadcastExcept(std::string event, ResponseUnit* sender);

public:
    IncidentCoordinator();
    virtual ~IncidentCoordinator();

    void registerUnit(ResponseUnit* unit) override;
    void notify(std::string event, ResponseUnit* sender) override;
    
    
    void respondToBuildingThreat();
    void dispatchUnit(ResponseUnit* unit, std::string location);
    std::string locationOf(ResponseUnit* unit);

    std::string getIncidentStatus() const;
};

#endif