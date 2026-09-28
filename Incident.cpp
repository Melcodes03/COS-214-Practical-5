#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"

Incident::Incident(int id, const std::string& desc, const std::string& loc)
    : incidentID(id), description(desc), location(loc), state(nullptr)
{
    // every incident starts off as just reported since nothing has happened yet
    state = new ReportedState();
}

Incident::~Incident() {
    delete state;
}

void Incident::setState(IncidentState* newState) {
    // we own the state object so we need to clean up the old one before swapping
    delete state;
    state = newState;
}

void Incident::transition() {
    state->handle(*this);
}

std::string Incident::getStatusName() const {
    return state->getStatusName();
}

int Incident::getID() const {
    return incidentID;
}

std::string Incident::getDescription() const {
    return description;
}

std::string Incident::getLocation() const {
    return location;
}