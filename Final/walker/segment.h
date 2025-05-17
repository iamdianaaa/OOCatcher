#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"

class segment {
protected:
    point start, end;
public:
    segment(const point& start, const point& end);
    virtual ~segment() {}
    virtual void rotate(double angle) = 0;
    virtual double length() const;
    const point& getStart() const;
    const point& getEnd() const;
    point& getStart();
    point& getEnd();

protected:
    void update_end(double length, double angle);
};

#endif
