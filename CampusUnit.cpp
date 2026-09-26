#include "CampusUnit.h"
#include "UnlockedState.h" 

CampusUnit::CampusUnit(ZoneState* st){
    this->state = st;
}

void CampusUnit::transition(ZoneState* st) {
    if(this->state != nullptr){
        delete this->state;
    }
    this->state = st;
}

bool CampusUnit::isLocked() {
    if (this->state != nullptr) {
        return this->state->getStatusName() == "Locked"; 
    }
    return false;
}

void CampusUnit::secure() {
    if (this->state != nullptr && this->state->getStatusName() == "Unlocked") {
        this->state->handle(*this); 
    }
}

void CampusUnit::unlock() {
    if (this->state != nullptr && this->state->getStatusName() == "Locked") {
        this->transition(new UnlockedState()); 
    }
}

CampusUnit::~CampusUnit(){
    delete this->state;
}