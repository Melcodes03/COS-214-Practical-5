#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

#include <string>

class CampusComponent {
public:
	virtual void add(CampusComponent* cmp) = 0;
	virtual void remove(CampusComponent* cmp) = 0;
	virtual void secure() = 0;
	virtual void unlock() = 0;
	virtual bool isLocked() = 0;
	virtual ~CampusComponent();
};

#endif