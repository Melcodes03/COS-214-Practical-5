#include "SecureZoneCommand.h"

SecureZoneCommand::SecureZoneCommand(CampusComponent* area) {
	this->target = area;
}

void SecureZoneCommand::execute() {
	if(this->target != nullptr){
		this->target->secure();
	}
	
}
