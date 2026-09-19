#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

// forward declaring this instead of including the header so we dont get
// a circular include between Incident and IncidentState
class IncidentState;

/**
 * This is our Context class for the State pattern.
 * It holds whatever the current state is and just forwards the work
 * to that state instead of using a big if else chain to check the status.
 */
class Incident {
private:
    int incidentID;
    std::string description;
    std::string location;
    IncidentState* state;

public:
    Incident(int id, const std::string& desc, const std::string& loc);
    ~Incident();

    // not allowing copies for now since we are manually managing the state pointer
    // and dont want two incidents accidentally sharing or double deleting the same state
    Incident(const Incident&) = delete;
    Incident& operator=(const Incident&) = delete;

    // swaps out the current state for a new one, called by the concrete states
    void setState(IncidentState* newState);

    // moves the incident on to whatever the next state should be
    void transition();

    std::string getStatusName() const;

    int getID() const;
    std::string getDescription() const;
    std::string getLocation() const;
};

#endif