#ifndef ZONE_STATE_H
#define ZONE_STATE_H

#include <string>

class CampusUnit;

/**
 * Abstract State class for a CampusUnit's lock/access lifecycle.
 * This is separate from IncidentState: an incident's status (Reported,
 * Dispatched, Resolved) is not the same thing as a unit's lock status
 * (Unlocked, Locked, Evacuation), so it gets its own hierarchy instead
 * of reusing IncidentState.
 */
class ZoneState {
public:
    virtual ~ZoneState() {}

    virtual void handle(CampusUnit& unit) = 0;
    virtual std::string getStatusName() const = 0;
};

#endif