#include "body.h"
#include <iostream>
#include <cmath>

Body::Body(double x, double y)
    : torso(Point(x, y), 5, M_PI / 2),
      armL(torso.getEnd(), 3, M_PI / 1.2),
      armR(torso.getEnd(), 3, M_PI / 6),
      legL(torso.getStart(), 4, -M_PI / 2),
      legR(torso.getStart(), 4, -M_PI / 2)
{
    legL.setStart(torso.getStart());
    legR.setStart(torso.getStart());
}

bool Body::checkGroundContact() const {
    int contacts = 0;
    if (std::abs(legL.getEnd().y - GROUND_Y) < 0.2) contacts++;
    if (std::abs(legR.getEnd().y - GROUND_Y) < 0.2) contacts++;
    if (std::abs(torso.getStart().y - GROUND_Y) < 0.2) contacts++;
    return contacts >= 2;
}

bool Body::rotateSegmentAndCheckGround(Segment& segment, double delta) {
    segment.rotate(delta);
    return checkGroundContact();
}

Segment& Body::getArmR() {
    return armR;
}

const Segment& Body::getArmR() const {
    return armR;
}


void Body::aimArmAt(const Point& target) {
    Point origin = armR.getStart();
    double angle = std::atan2(target.y - origin.y, target.x - origin.x);
    armR = Segment(origin, 3, angle); 
}

void Body::throwSnowball(const Point& target, double target_radius) {
    if (!checkGroundContact()) {
        std::cout << "Cannot throw: not enough ground contact.\n";
        return;
    }

    Segment fakeLegL = legL, fakeLegR = legR, fakeTorso = torso;
    fakeLegL.setStart(fakeLegL.getStart() + Point(0, 0.5));
    fakeLegR.setStart(fakeLegR.getStart() + Point(0, 0.5));
    fakeTorso.setStart(fakeTorso.getStart() + Point(0, 0.5));

    if (std::abs(fakeLegL.getEnd().y - GROUND_Y) < 0.2 ||
        std::abs(fakeLegR.getEnd().y - GROUND_Y) < 0.2 ||
        std::abs(fakeTorso.getStart().y - GROUND_Y) < 0.2) {
        std::cout << "Cannot throw: segments still touching ground after detach attempt.\n";
        return;
    }

    Point throw_origin = armR.getEnd();
    Point direction = target - throw_origin;
    double norm = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (norm == 0) {
        std::cout << "Invalid target direction.\n";
        return;
    }

    Point velocity = direction * (10.0 / norm); 

    std::cout << "Snowball thrown!\n";
    std::cout << "Initial Position: (" << throw_origin.x << ", " << throw_origin.y << ")\n";
    std::cout << "Velocity Vector: (" << velocity.x << ", " << velocity.y << ")\n";

    Point toTarget = target - throw_origin;
    double throwLen = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    double proj = (direction.x * toTarget.x + direction.y * toTarget.y) / throwLen;

    bool hit = false;
    if (proj > 0 && proj <= throwLen) {
        Point closestPoint = throw_origin + (direction * (proj / throwLen));
        double distanceToTarget = closestPoint.dist(target);
        std::cout << "Closest approach: " << distanceToTarget << ", Target Radius: " << target_radius << "\n";
        if (distanceToTarget <= target_radius) {
            hit = true;
        }
    }

    if (hit) {
        std::cout << "Target hit!\n";
    } else {
        std::cout << "Target missed.\n";
    }
}

