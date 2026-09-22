#include "ActivateEmergencyCommand.h"

ActivateEmergencyCommand::ActivateEmergencyCommand(AlertService* alarm, std::string msg) {
	this->alarm = alarm;
	this->message = msg;
}

void ActivateEmergencyCommand::execute() {
	if(this->alarm != nullptr){
		this->alarm->broadcast(this->message);
	}
}
