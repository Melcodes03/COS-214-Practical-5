#ifndef LOCKED_STATE_H
#define LOCKED_STATE_H

#include "ZoneState.h"

// state for when a unit has been secured and access is restricted
class LockedState : public ZoneState {
public:
    void handle(CampusUnit& unit) override;
    std::string getStatusName() const override;
};

#endif