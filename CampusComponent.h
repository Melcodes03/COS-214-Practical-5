#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

#include <string>
#include "ResponseUnit.h"


class CampusComponent : public ResponseUnit {

public:
	virtual void add(CampusComponent* cmp) = 0;

	virtual void remove(CampusComponent* cmp) = 0;

	virtual void secure() = 0;

	virtual void unlock() = 0;

	virtual bool isLocked() = 0;

	virtual void send(std::string event) = 0;

	virtual void receive(std::string event) = 0;

	virtual ~CampusComponent();
};

#endif
