#include "circle.h"
#include <cmath>

circle::circle(double x, double y, double radius) : center(x, y), radius(radius) {}

bool circle::contains(const point& p) const {
    return center.dist(p) < radius;
}

bool circle::onPerimeter(const point& p, double tolerance) const {
    double d = center.dist(p);
    return std::abs(d - radius) <= tolerance;
}

const point& circle::getCenter() const {
    return center;
}

double circle::getRadius() const {
    return radius;
}