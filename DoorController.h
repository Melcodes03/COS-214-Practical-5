#ifndef DOORCONTROLLER_H
#define DOORCONTROLLER_H

class DoorController {
private:
    bool bolted;

public:
    DoorController();

    void engageBolt();
    void releaseBolt();
    bool isBolted() const;
};

#endif
