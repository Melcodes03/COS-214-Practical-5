#ifndef CAMPUSCOMMAND_H
#define CAMPUSCOMMAND_H

class CampusCommand {
public:
    virtual void execute() = 0;
    virtual ~CampusCommand() {} 
};

#endif