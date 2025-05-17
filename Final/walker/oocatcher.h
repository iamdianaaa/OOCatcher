#ifndef OOCATCHER_H
#define OOCATCHER_H

#include "body.h"
#include "circle.h"

class oocatcher {
private:
    body b;
    circle obj;
public:
    oocatcher(const body& b, const circle& obj);
    void run();
};

#endif
