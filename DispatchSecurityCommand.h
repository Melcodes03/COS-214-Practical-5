#ifndef DISPATCHSECURITYCOMMAND_H
#define DISPATCHSECURITYCOMMAND_H

#include "CampusCommand.h"

#include "CampusCommand.h"
class DispatchSecurityCommand : public CampusCommand {

private:
	SecurityUnit* resp;
	CampusComponent* destination;

public:
	virtual void execute();

	DispatchSecurityCommand(SecurityUnit* su, CampusComponent* dest);
};

#endif
