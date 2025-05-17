#ifndef BODY_H
#define BODY_H

#include "simplesegment.h"

class body {
private:
    simplesegment torso, armL, armR, legL, legR;
public:
    body(double x, double y);
    void walk(double step_size, const point& target);
    void reach(const point& target);
    bool checkGroundContact() const;
    bool catchObject(const point& target) const;
    const simplesegment& getArmL() const;
    const simplesegment& getArmR() const;
    const simplesegment& getLegL() const;
    const simplesegment& getLegR() const;
    const simplesegment& getTorso() const;
};

#endif
