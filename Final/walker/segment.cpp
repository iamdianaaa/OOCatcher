#include "segment.h"
#include <cmath>

segment::segment(const point& start, const point& end) : start(start), end(end) {}

double segment::length() const {
    return start.dist(end);
}

const point& segment::getStart() const {
    return start;
}

const point& segment::getEnd() const {
    return end;
}

point& segment::getStart() {
    return start;
}

point& segment::getEnd() {
    return end;
}

void segment::update_end(double len, double angle) {
    end.x = start.x + len * std::cos(angle);
    end.y = start.y + len * std::sin(angle);
}
