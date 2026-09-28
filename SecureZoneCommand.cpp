#include "SecureZoneCommand.h"

SecureZoneCommand::SecureZoneCommand(FacilitiesUnit* fac, CampusComponent* area) {
	this->facilities = fac;
	this->target = area;
}

void SecureZoneCommand::execute() {
	if(this->facilities != nullptr && this->target != nullptr){
		this->facilities->secureArea(this->target); 
	}
}