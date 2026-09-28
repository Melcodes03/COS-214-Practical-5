#ifndef SECUREZONECOMMAND_H
#define SECUREZONECOMMAND_H

#include "CampusCommand.h"
#include "CampusComponent.h"
#include "FacilitiesUnit.h"

class SecureZoneCommand : public CampusCommand {
private:
	FacilitiesUnit* facilities;
	CampusComponent* target;

public:
	SecureZoneCommand(FacilitiesUnit* fac, CampusComponent* area);
	virtual void execute();
};

#endif