#ifndef ACTIVATEEMERGENCYCOMMAND_H
#define ACTIVATEEMERGENCYCOMMAND_H

#include <string>
#include "CampusCommand.h"

class ActivateEmergencyCommand : public CampusCommand {

private:
	AlertService* alarm;
	std::string message;

public:
	ActivateEmergencyCommand(AlertService* alarm, std::string msg);

	void execute();
};

#endif
