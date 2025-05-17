#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class circle {
private:
    point center;
    double radius;
public:
    circle(double x, double y, double radius);
    bool contains(const point& p) const;
    bool onPerimeter(const point& p, double tolerance = 0.1) const;
    const point& getCenter() const;
    double getRadius() const;  
};

#endif