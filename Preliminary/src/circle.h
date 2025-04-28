#pragma once
#include "point.h"

class circle
{
public:
    circle(double center_x, double center_y, double radius);

    double get_x() const;
    double get_y() const;
    double get_radius() const;

    bool contains(const point& p) const;
    bool on_perimeter(const point& p, double tolerance = 0.5) const;

private:
    point center;
    double radius;
};
