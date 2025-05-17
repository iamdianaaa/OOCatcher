#include "point.h"
#include <cmath>

point::point(double x, double y) : x(x), y(y) {}

double point::dist(const point& other) const {
    return std::sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
}

double point::dir(const point& other) const {
    return std::atan2(other.y - y, other.x - x);
}

void point::move(double dx, double dy) {
    x += dx;
    y += dy;
}
