#ifndef UNLOCKED_STATE_H
#define UNLOCKED_STATE_H

#include "ZoneState.h"

// default state a unit starts in, before any secure command is issued
class UnlockedState : public ZoneState {
public:
    void handle(CampusUnit& unit) override;
    std::string getStatusName() const override;
};

#endif