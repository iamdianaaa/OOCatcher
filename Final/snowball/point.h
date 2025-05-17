#pragma once

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0);

    double dist(const Point& other) const;

    Point operator-(const Point& other) const;
    Point operator+(const Point& other) const;
    Point operator*(double scalar) const;
};
