#ifndef EVACUATION_STATE_H
#define EVACUATION_STATE_H

#include "ZoneState.h"

// terminal state for this cycle, doors are open and unit is clear to evacuate
class EvacuationState : public ZoneState {
public:
    void handle(CampusUnit& unit) override;
    std::string getStatusName() const override;
};

#endif