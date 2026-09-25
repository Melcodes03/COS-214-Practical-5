#include "CampusArea.h"

CampusArea::CampusArea(){

}

void CampusArea::add(CampusComponent* cmp) {
	if(cmp != nullptr){
		this->components.push_back(cmp);
	}
}

void CampusArea::remove(CampusComponent* cmp) {
    this->components.erase(
        std::remove(this->components.begin(), this->components.end(), cmp), 
        this->components.end() 
    );
}

void CampusArea::secure() {
	for(const auto& comp : this->components){
		comp->secure();
	}
}

void CampusArea::unlock() {
	for(const auto& comp : this->components){
		comp->unlock();
	}
}

bool CampusArea::isLocked() {
	if (this->components.empty()) return false;
    for(const auto& comp : this->components){
        if (!comp->isLocked()) {
            return false; 
        }
    }
    return true;
}

void CampusArea::send(string event) {
	// TODO - implement CampusArea::send
	throw "Not yet implemented";
}

void CampusArea::receive(string event) {
	// TODO - implement CampusArea::receive
	throw "Not yet implemented";
}

CampusArea::~CampusArea(){
	for(auto& comp : this->components){
		delete comp;
	}
}
