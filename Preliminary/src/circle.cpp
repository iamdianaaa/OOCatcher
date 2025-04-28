#include "circle.h"
#include <cmath>

circle::circle(double center_x, double center_y, double radius)
    : center(center_x, center_y), radius(radius)
{}

double circle::get_x() const { return center.get_x(); }
double circle::get_y() const { return center.get_y(); }
double circle::get_radius() const { return radius; }

bool circle::contains(const point& p) const {
    return center.dist(p) < radius;
}

bool circle::on_perimeter(const point& p, double tolerance) const {
    double d = center.dist(p);
    return std::abs(d - radius) <= tolerance;
}
