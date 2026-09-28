#include "ResponseUnit.h"
#include "ResponseHub.h"

ResponseUnit::ResponseUnit() : hub(nullptr), unitName("") {}

ResponseUnit::ResponseUnit(ResponseHub* hub, std::string name) : hub(hub), unitName(name) {}

ResponseUnit::~ResponseUnit() {}

void ResponseUnit::send(std::string event) {
    if (hub != nullptr) {
        hub->notify(event, this);
    }
}

std::string ResponseUnit::getName() const {
    return unitName;
}
