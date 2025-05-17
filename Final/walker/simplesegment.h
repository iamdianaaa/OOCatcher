#ifndef SIMPLESEGMENT_H
#define SIMPLESEGMENT_H

#include "segment.h"

class simplesegment : public segment {
private:
    double min_angle, max_angle;  
    double current_angle;
public:
    simplesegment(const point& start, double length, double angle, double min_angle, double max_angle);
    void rotate(double delta) override;
};

#endif
