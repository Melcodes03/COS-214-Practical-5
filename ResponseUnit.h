#ifndef RESPONSEUNIT_H
#define RESPONSEUNIT_H

#include <string>

class ResponseHub;

class ResponseUnit {
protected:
    ResponseHub* hub;
    std::string unitName;

public:
    ResponseUnit();
    ResponseUnit(ResponseHub* hub, std::string name);
    virtual ~ResponseUnit();

    void send(std::string event);
    virtual void receive(std::string event) = 0;

    std::string getName() const;
};

#endif
