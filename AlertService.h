#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

#include "ResponseUnit.h"

class AlertService : public ResponseUnit {
public:
    AlertService(ResponseHub* hub, std::string name);
    virtual ~AlertService();

    void broadcast(std::string message);

    void receive(std::string event);
};

#endif
