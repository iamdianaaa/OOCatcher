#include "segment.h"
#include <cmath>

Segment::Segment(Point start, double length, double angleRad)
    : start(start), length(length), angle(angleRad) {
    updateEnd();
}

void Segment::rotate(double delta) {
    angle += delta;
    updateEnd();
}

void Segment::setStart(const Point& p) {
    start = p;
    updateEnd();
}

Point Segment::getStart() const { return start; }
Point Segment::getEnd() const { return end; }
double Segment::getAngle() const { return angle; }

void Segment::updateEnd() {
    end.x = start.x + length * std::cos(angle);
    end.y = start.y + length * std::sin(angle);
}
