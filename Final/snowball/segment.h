#pragma once
#include "point.h"

class Segment {
private:
    Point start;
    Point end;
    double length;
    double angle;

    void updateEnd();

public:
    Segment(Point start, double length, double angleRad);

    void rotate(double delta);
    void setStart(const Point& p);

    Point getStart() const;
    Point getEnd() const;
    double getAngle() const;
};
