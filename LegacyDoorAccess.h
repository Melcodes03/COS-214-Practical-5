#ifndef LEGACYDOORACCESS_H
#define LEGACYDOORACCESS_H

#include "AccessPoint.h"
class DoorController;

class LegacyDoorAccess : public AccessPoint {
private:
    DoorController* controller;
public:
    explicit LegacyDoorAccess(DoorController* controller);
    virtual ~LegacyDoorAccess();
    void lock() override; 
    void unlock() override;
    bool isLocked() override;
};
#endif