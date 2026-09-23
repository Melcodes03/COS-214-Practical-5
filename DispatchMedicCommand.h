#ifndef DISPATCHMEDICCOMMAND_H
#define DISPATCHMEDICCOMMAND_H

#include "CampusCommand.h"
#include "CampusComponent.h"

class DispatchMedicCommand : public CampusCommand {

private:
	MedicUnit* resp;
	CampusComponent* destination;

public:
	virtual void execute();

	DispatchMedicCommand(MedicUnit* mu, CampusComponent* dest);
};

#endif
