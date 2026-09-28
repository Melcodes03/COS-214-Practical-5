#ifndef INCIDENT_STATE_H
#define INCIDENT_STATE_H

#include <string>

class Incident;

/**
 * Abstract State class. Every concrete state needs to say what happens
 * when handle() is called and what its own name is so we can print it
 * out or use it for logging.
 */
class IncidentState {
public:
    virtual ~IncidentState() {}

    virtual void handle(Incident& incident) = 0;
    virtual std::string getStatusName() const = 0;
};

#endif