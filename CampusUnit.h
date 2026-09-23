#ifndef CAMPUSUNIT_H
#define CAMPUSUNIT_H

#include "IncidentState.h"
#include "AccessPoint.h"
#include <string>
#include "CampusComponent.h"

class CampusUnit : public CampusComponet {
private:
	IncidentState* state;
	AccessPoint* ap;

public:
	CampusUnit(IncidentState* st, AccessPoint* ap);

	void transition(IncidentState* st);

	virtual void send(std::string event);

	virtual void receive(std::string event);

	virtual bool isLocked();

	virtual void secure();

	virtual void unlock();

	virtual ~CampusUnit();
};

#endif
