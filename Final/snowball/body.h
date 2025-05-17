#pragma once
#include "segment.h"

class Body {
private:
    Segment torso;
    Segment armL, armR, legL, legR;
    static constexpr double GROUND_Y = 0.0;

public:
    Body(double x, double y);

    bool checkGroundContact() const;
    void throwSnowball(const Point& target, double target_radius);

    bool rotateSegmentAndCheckGround(Segment& segment, double delta);
    Segment& getArmR();
    const Segment& getArmR() const;

    void aimArmAt(const Point& target); 
};
