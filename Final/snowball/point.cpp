#include "point.h"
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::dist(const Point& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator*(double scalar) const {
    return Point(x * scalar, y * scalar);
}
