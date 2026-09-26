#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

class AccessPoint {
public:
    virtual ~AccessPoint() {}
    virtual void lock() = 0; 
    virtual void unlock() = 0;
    virtual bool isLocked() = 0;
};

#endif