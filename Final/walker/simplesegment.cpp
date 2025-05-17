#include "simplesegment.h"
#include <cmath>
#include <iostream>

simplesegment::simplesegment(const point& start, double length, double angle, double min_angle, double max_angle)
    : segment(start, point()), min_angle(min_angle), max_angle(max_angle), current_angle(angle)
{
    end.x = start.x + length * std::cos(angle);
    end.y = start.y + length * std::sin(angle);
}

void simplesegment::rotate(double delta) {
    current_angle += delta;
    
    if (current_angle < min_angle) current_angle = min_angle;
    if (current_angle > max_angle) current_angle = max_angle;
    
    double len = length();
    
    end.x = start.x + len * std::cos(current_angle);
    end.y = start.y + len * std::sin(current_angle);

    std::cout << "Rotated: start=(" << start.x << "," << start.y 
          << ") end=(" << end.x << "," << end.y << ")" << std::endl;
}