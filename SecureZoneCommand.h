#ifndef SECUREZONECOMMAND_H
#define SECUREZONECOMMAND_H

#include "CampusCommand.h"
#include "CampusComponent.h"

class SecureZoneCommand : public CampusCommand {
	private:
	CampusComponent* target;

public:
	

	SecureZoneCommand(CampusComponent* area);

	virtual void execute();
};

#endif
