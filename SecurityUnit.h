#ifndef SECURITYUNIT_H
#define SECURITYUNIT_H

#include "ResponseUnit.h"

class CampusComponent;

class SecurityUnit : public ResponseUnit {
private:
    CampusComponent* destination;
    bool onStandby;

public:
    SecurityUnit(ResponseHub* hub, std::string name);
    virtual ~SecurityUnit();

    void dispatch(CampusComponent* destination);
    CampusComponent* getDestination() const;

    void receive(std::string event);
};

#endif
