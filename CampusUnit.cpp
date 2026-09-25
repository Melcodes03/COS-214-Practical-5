#include "CampusUnit.h"

CampusUnit::CampusUnit(ZoneState* st, AccessPoint* ap){
	this->ap = ap;
	this->state = st;
}

void CampusUnit::transition(ZoneState* st) {
	if(this->state != nullptr){
		delete this->state;
	}

	this->state = st;

}

void CampusUnit::send(std::string event) {
	// TODO - implement CampusUnit::send
	throw "Not yet implemented";
}

void CampusUnit::receive(std::string event) {
	// TODO - implement CampusUnit::receive
	throw "Not yet implemented";
}

bool CampusUnit::isLocked() {
	if(this->ap != nullptr){
		this->ap->isLocked();
	}

	return false;
}

void CampusUnit::secure() {
	if(this->ap != nullptr){
		this->ap->secure();
	}
}

void CampusUnit::unlock() {
	if(this->ap != nullptr){
		this->ap->unlock();
	}
}

CampusUnit::~CampusUnit(){
	delete this->ap;
	delete this->state;

}