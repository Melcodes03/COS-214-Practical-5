#ifndef DISPATCHED_STATE_H
#define DISPATCHED_STATE_H

#include "IncidentState.h"

// state for when response units have already been sent to the incident
class DispatchedState : public IncidentState {
public:
    void handle(Incident& incident) override;
    std::string getStatusName() const override;
};

#endif