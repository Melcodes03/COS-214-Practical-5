#ifndef RESPONSEHUB_H
#define RESPONSEHUB_H

#include <string>

class ResponseUnit;

class ResponseHub {
public:
    virtual ~ResponseHub() {}
    virtual void notify(std::string event, ResponseUnit* sender) = 0;
    virtual void registerUnit(ResponseUnit* unit) = 0;
};

#endif
