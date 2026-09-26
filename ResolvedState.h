#ifndef RESOLVED_STATE_H
#define RESOLVED_STATE_H

#include "IncidentState.h"

// this is basically the end state, incident is closed off here
class ResolvedState : public IncidentState {
public:
    void handle(Incident& incident) override;
    std::string getStatusName() const override;
};

#endif