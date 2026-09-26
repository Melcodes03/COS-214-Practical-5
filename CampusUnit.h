#ifndef CAMPUSUNIT_H
#define CAMPUSUNIT_H

#include "ZoneState.h"
#include <string>
#include "CampusComponent.h"

class CampusUnit : public CampusComponent {
private:
    ZoneState* state; 

public:
    CampusUnit(ZoneState* st); 
    
    void transition(ZoneState* st);
    
    virtual bool isLocked() override;
    virtual void secure() override;
    virtual void unlock() override;
    virtual ~CampusUnit();
};

#endif