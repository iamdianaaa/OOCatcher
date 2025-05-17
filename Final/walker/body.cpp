#include "body.h"
#include <cmath>
#include <iostream>

body::body(double x, double y)
    : torso(point(x, y), 5, M_PI/2, M_PI/4, 3*M_PI/4),
      armL(torso.getEnd(), 3, M_PI, M_PI/2, 3*M_PI/2),
      armR(torso.getEnd(), 3, 0, -M_PI/2, M_PI/2),
      legL(torso.getStart(), 4, M_PI, 0, 2*M_PI),
      legR(torso.getStart(), 4, M_PI, 0, 2*M_PI)
{
    std::cout << "Initial setup:" << std::endl;
    std::cout << "Torso: (" << torso.getStart().x << "," << torso.getStart().y << ") to ("
              << torso.getEnd().x << "," << torso.getEnd().y << ")" << std::endl;
}

void body::walk(double step_size, const point& target) {
    double dx = target.x - torso.getStart().x;
    double dy = target.y - torso.getStart().y;
    double distance = std::sqrt(dx * dx + dy * dy);
    
    if (distance > step_size) {
        dx = (dx / distance) * step_size;
        dy = (dy / distance) * step_size;
    }
    
    point oldTorsoStart = torso.getStart();
    point oldTorsoEnd = torso.getEnd();
    
    torso.getStart().x += dx;
    torso.getStart().y += dy;
    
    torso.getEnd().x += dx;
    torso.getEnd().y += dy;
    
    armL.getStart() = torso.getEnd();
    armR.getStart() = torso.getEnd();
    
    legL.getStart() = torso.getStart();
    legR.getStart() = torso.getStart();
    
    point arm_L_delta = point(armL.getEnd().x - oldTorsoEnd.x, armL.getEnd().y - oldTorsoEnd.y);
    point arm_R_delta = point(armR.getEnd().x - oldTorsoEnd.x, armR.getEnd().y - oldTorsoEnd.y);
    point leg_L_delta = point(legL.getEnd().x - oldTorsoStart.x, legL.getEnd().y - oldTorsoStart.y);
    point leg_R_delta = point(legR.getEnd().x - oldTorsoStart.x, legR.getEnd().y - oldTorsoStart.y);
    
    armL.getEnd().x = torso.getEnd().x + arm_L_delta.x;
    armL.getEnd().y = torso.getEnd().y + arm_L_delta.y;
    
    armR.getEnd().x = torso.getEnd().x + arm_R_delta.x;
    armR.getEnd().y = torso.getEnd().y + arm_R_delta.y;
    
    legL.getEnd().x = torso.getStart().x + leg_L_delta.x;
    legL.getEnd().y = torso.getStart().y + leg_L_delta.y;
    
    legR.getEnd().x = torso.getStart().x + leg_R_delta.x;
    legR.getEnd().y = torso.getStart().y + leg_R_delta.y;
    
    armL.rotate(0.1);
    armR.rotate(-0.1);
    legL.rotate(0.05);
    legR.rotate(-0.05);
    
    std::cout << "Torso position: (" << torso.getStart().x << ", " << torso.getStart().y 
              << ") to (" << torso.getEnd().x << ", " << torso.getEnd().y << ")" << std::endl;
}

void body::reach(const point& target) {
    point oldTorsoStart = torso.getStart();
    point oldTorsoEnd = torso.getEnd();
    
    double distL_arm = armL.getEnd().dist(target);
    double distR_arm = armR.getEnd().dist(target);
    double distL_leg = legL.getEnd().dist(target);
    double distR_leg = legR.getEnd().dist(target);
    
    double angle_L = std::atan2(target.y - armL.getStart().y, target.x - armL.getStart().x);
    double angle_R = std::atan2(target.y - armR.getStart().y, target.x - armR.getStart().x);
    double current_L = std::atan2(armL.getEnd().y - armL.getStart().y, armL.getEnd().x - armL.getStart().x);
    double current_R = std::atan2(armR.getEnd().y - armR.getStart().y, armR.getEnd().x - armR.getStart().x);

    double diff_L = angle_L - current_L;
    double diff_R = angle_R - current_R;
    while (diff_L > M_PI) diff_L -= 2 * M_PI;
    while (diff_L < -M_PI) diff_L += 2 * M_PI;
    while (diff_R > M_PI) diff_R -= 2 * M_PI;
    while (diff_R < -M_PI) diff_R += 2 * M_PI;

    if (std::abs(diff_L) > 0.05) armL.rotate(diff_L > 0 ? 0.5 : -0.5);
    if (std::abs(diff_R) > 0.05) armR.rotate(diff_R > 0 ? 0.5 : -0.5);

    double torso_angle = std::atan2(torso.getEnd().y - torso.getStart().y,
                                   torso.getEnd().x - torso.getStart().x);
    double target_angle = std::atan2(target.y - torso.getStart().y,
                                    target.x - torso.getStart().x);
    double torso_diff = target_angle - torso_angle;

    while (torso_diff > M_PI) torso_diff -= 2 * M_PI;
    while (torso_diff < -M_PI) torso_diff += 2 * M_PI;

    if (std::abs(torso_diff) > 0.05) {
        double torso_step = torso_diff > 0 ? 0.2 : -0.2;
        point oldEnd = torso.getEnd();

        torso.rotate(torso_step);

        armL.getStart() = torso.getEnd();
        armR.getStart() = torso.getEnd();
        
        armL.getEnd().x += (torso.getEnd().x - oldEnd.x);
        armL.getEnd().y += (torso.getEnd().y - oldEnd.y);
        armR.getEnd().x += (torso.getEnd().x - oldEnd.x);
        armR.getEnd().y += (torso.getEnd().y - oldEnd.y);

        legL.getStart() = torso.getStart();
        legR.getStart() = torso.getStart();

        double dx = torso.getStart().x - oldTorsoStart.x;
        double dy = torso.getStart().y - oldTorsoStart.y;

        legL.getEnd().x += dx;
        legL.getEnd().y += dy;
        legR.getEnd().x += dx;
        legR.getEnd().y += dy;
    }

    double angle_LL = std::atan2(target.y - legL.getStart().y, target.x - legL.getStart().x);
    double angle_LR = std::atan2(target.y - legR.getStart().y, target.x - legR.getStart().x);

    double current_LL = std::atan2(legL.getEnd().y - legL.getStart().y, legL.getEnd().x - legL.getStart().x);
    double current_LR = std::atan2(legR.getEnd().y - legR.getStart().y, legR.getEnd().x - legR.getStart().x);

    double diff_LL = angle_LL - current_LL;
    double diff_LR = angle_LR - current_LR;

    while (diff_LL > M_PI) diff_LL -= 2 * M_PI;
    while (diff_LL < -M_PI) diff_LL += 2 * M_PI;
    while (diff_LR > M_PI) diff_LR -= 2 * M_PI;
    while (diff_LR < -M_PI) diff_LR += 2 * M_PI;

    if (std::abs(diff_LL) > 0.05) {
        double test_angle = diff_LL > 0 ? 0.4 : -0.4;
        double old_y = legL.getEnd().y;
        legL.rotate(test_angle);
        
        if (legL.getEnd().y > 0.5 && checkGroundContact() == false) {
            legL.getEnd().y = old_y;
        }
    }
    
    if (std::abs(diff_LR) > 0.05) {
        double test_angle = diff_LR > 0 ? 0.4 : -0.4;
        double old_y = legR.getEnd().y;
        legR.rotate(test_angle);
        
        if (legR.getEnd().y > 0.5 && checkGroundContact() == false) {
            legR.getEnd().y = old_y;
        }
    }

    double min_dist = std::min(std::min(distL_arm, distR_arm), std::min(distL_leg, distR_leg));

    if (min_dist < 4.0) {
        double lean_angle = 0.15;
        
        bool was_on_ground = checkGroundContact();
        double old_torso_x = torso.getStart().x;
        double old_torso_y = torso.getStart().y;
        
        torso.getStart().x += 0.1;
        
        if (!checkGroundContact() && was_on_ground) {
            torso.getStart().x = old_torso_x;
            torso.getStart().y = old_torso_y;
        }
    }

    std::cout << "Reaching - arms at: L(" << armL.getEnd().x << ", " << armL.getEnd().y
              << "), R(" << armR.getEnd().x << ", " << armR.getEnd().y << ")" << std::endl;
    std::cout << "Distance to target - L: " << armL.getEnd().dist(target)
              << ", R: " << armR.getEnd().dist(target) << std::endl;
}

bool body::checkGroundContact() const {
    int points_on_ground = 0;
    double ground_tolerance = 0.1;
    
    if (std::abs(legL.getEnd().y) <= ground_tolerance) points_on_ground++;
    if (std::abs(legR.getEnd().y) <= ground_tolerance) points_on_ground++;
    if (std::abs(torso.getStart().y) <= ground_tolerance) points_on_ground++;
    
    return points_on_ground >= 2;
}

bool body::catchObject(const point& target) const {
    double catch_threshold = 3.5; 
    int touching_points = 0;

    double armL_dist = armL.getEnd().dist(target);
    double armR_dist = armR.getEnd().dist(target);
    double legL_dist = legL.getEnd().dist(target);
    double legR_dist = legR.getEnd().dist(target);

    if (armL_dist <= catch_threshold) touching_points++;
    if (armR_dist <= catch_threshold) touching_points++;
    if (legL_dist <= catch_threshold) touching_points++;
    if (legR_dist <= catch_threshold) touching_points++;

    std::cout << "Touching points: " << touching_points << std::endl;
    std::cout << "Distances - armL: " << armL_dist
              << ", armR: " << armR_dist
              << ", legL: " << legL_dist
              << ", legR: " << legR_dist << std::endl;

    return touching_points >= 3;
}


const simplesegment& body::getArmL() const { return armL; }
const simplesegment& body::getArmR() const { return armR; }
const simplesegment& body::getLegL() const { return legL; }
const simplesegment& body::getLegR() const { return legR; }
const simplesegment& body::getTorso() const { return torso; }