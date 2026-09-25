#include "DispatchMedicCommand.h"

void DispatchMedicCommand::execute() {
	if ((this->destination != nullptr) && (this->resp != nullptr)) {
        this->resp->dispatch(this->destination); 
    }
}

DispatchMedicCommand::DispatchMedicCommand(MedicUnit* mu, CampusComponent* dest) {
	this->resp = mu;
	this->destination = dest;
	
}
