#ifndef REPORTED_STATE_H
#define REPORTED_STATE_H

#include "IncidentState.h"

// this is the state an incident is created in, before any units are sent out
class ReportedState : public IncidentState {
public:
    void handle(Incident& incident) override;
    std::string getStatusName() const override;
};

#endif