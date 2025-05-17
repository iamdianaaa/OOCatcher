#ifndef POINT_H
#define POINT_H

class point {
public:
    double x, y;
    point(double x = 0, double y = 0);
    double dist(const point& other) const;
    double dir(const point& other) const;
    void move(double dx, double dy);
};

#endif
