#ifndef MEDICUNIT_H
#define MEDICUNIT_H

#include "ResponseUnit.h"

class CampusComponent;

class MedicUnit : public ResponseUnit {
private:
    CampusComponent* destination;
    bool dispatched;

public:
    MedicUnit(ResponseHub* hub, std::string name);
    virtual ~MedicUnit();

    void dispatch(CampusComponent* destination);
    CampusComponent* getDestination() const;

    void receive(std::string event);
};

#endif
