#include "oocatcher.h"
#include <iostream>
#include <cmath>

oocatcher::oocatcher(const body& b, const circle& obj) : b(b), obj(obj) {}

void oocatcher::run() {
    int steps = 0;
    const int MAX_STEPS = 50;
    
    std::cout << "Object center: (" << obj.getCenter().x << ", " << obj.getCenter().y 
              << "), radius: " << obj.getRadius() << std::endl;
    std::cout << "Initial torso position: (" << b.getTorso().getStart().x << ", " 
              << b.getTorso().getStart().y << ") to (" 
              << b.getTorso().getEnd().x << ", " << b.getTorso().getEnd().y << ")" << std::endl;
    
    double horizontal_distance = std::abs(b.getTorso().getStart().x - obj.getCenter().x);
    std::cout << "Initial horizontal distance: " << horizontal_distance << std::endl;
    
    double targetDistance = 0.5; 
    
    while (horizontal_distance > targetDistance && steps < MAX_STEPS) {
        b.walk(0.5, obj.getCenter());
        
        horizontal_distance = std::abs(b.getTorso().getStart().x - obj.getCenter().x);
        std::cout << "Walking - horizontal distance: " << horizontal_distance << std::endl;
        
        steps++;
    }
    
    if (steps >= MAX_STEPS) {
        std::cout << "Reached maximum step count. Could not reach object." << std::endl;
        return;
    }
    
    std::cout << "In position to grab!" << std::endl;
    
    bool grabbed = false;
    for (int i = 0; i < 50 && !grabbed; i++) {
        b.reach(obj.getCenter());
        
        if (b.catchObject(obj.getCenter())) {
            std::cout << "Object successfully grabbed!" << std::endl;
            grabbed = true;
            break;
        }
    }
    
    if (!grabbed) {
        std::cout << "Attempted to grab but failed." << std::endl;
    }
}