#ifndef CAMPUSAREA_H
#define CAMPUSAREA_H

#include "CampusComponent.h"
#include <string>
#include <vector>

class CampusArea : public CampusComponent {
private:
	std::vector<CampusComponent*> components;

public:
	CampusArea();

	virtual void add(CampusComponent* cmp);

	virtual void remove(CampusComponent* cmp);

	virtual void secure();

	virtual void unlock();

	virtual bool isLocked();

	virtual void send(std::string event);

	virtual void receive(std::string event);

	virtual ~CampusArea();
};

#endif
