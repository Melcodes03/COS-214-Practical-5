#ifndef FACILITIESUNIT_H
#define FACILITIESUNIT_H

#include "ResponseUnit.h"
#include "AccessPoint.h"
#include "CampusComponent.h"
#include <vector>
#include <string>

class FacilitiesUnit : public ResponseUnit {
private:
    std::vector<AccessPoint*> accessPoints; 
    bool accessRestricted;

public:
    FacilitiesUnit(ResponseHub* hub, std::string name);
    virtual ~FacilitiesUnit();

    void secureArea(CampusComponent* area);

    void addAccessPoint(AccessPoint* ap);

    void receive(std::string event) override;
};

#endif