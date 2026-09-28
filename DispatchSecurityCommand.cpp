#include "DispatchSecurityCommand.h"

void DispatchSecurityCommand::execute() {
	if ((this->destination != nullptr) && (this->resp != nullptr)) {
        this->resp->dispatch(this->destination); 
    }
}

DispatchSecurityCommand::DispatchSecurityCommand(SecurityUnit* su, CampusComponent* dest) {
	this->resp = su;
	this->destination = dest;
}
