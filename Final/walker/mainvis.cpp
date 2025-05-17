#include "body.h"
#include "circle.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

void drawScene(const body& b, const circle& obj) {
    int maxWidth = 80;
    int scale = 2;
    int bodyX = static_cast<int>(b.getTorso().getStart().x * scale);
    int objectX = static_cast<int>(obj.getCenter().x * scale);

    std::string pad(bodyX, ' ');

    bool armL_touch = b.getArmL().getEnd().dist(obj.getCenter()) <= 3.5;
    bool armR_touch = b.getArmR().getEnd().dist(obj.getCenter()) <= 3.5;
    bool legL_touch = b.getLegL().getEnd().dist(obj.getCenter()) <= 3.5;
    bool legR_touch = b.getLegR().getEnd().dist(obj.getCenter()) <= 3.5;

    int touching = armL_touch + armR_touch + legL_touch + legR_touch;

    // Object
    for (int i = 0; i < maxWidth; ++i)
        std::cout << (i == objectX ? "O" : " ");
    std::cout << "\n";

    // Head and arms based on state
    if (touching >= 3) {
        std::cout << pad << " \\o/  <- grabbed!\n";
    } else if (armL_touch && armR_touch) {
        std::cout << pad << " \\o/  <- reaching\n";
    } else if (armL_touch) {
        std::cout << pad << " \\o   <- left reaching\n";
    } else if (armR_touch) {
        std::cout << pad << "  o/  <- right reaching\n";
    } else {
        std::cout << pad << "  o\n";
        std::cout << pad << " /|\\ \n";
    }

    // Torso
    std::cout << pad << "  | \n";

    // Legs
    if (legL_touch && legR_touch) {
        std::cout << pad << " /_\\  <- both legs grounded\n";
    } else if (legL_touch) {
        std::cout << pad << " /_\\  <- left leg grounded\n";
    } else if (legR_touch) {
        std::cout << pad << " / \\  <- right leg grounded\n";
    } else {
        std::cout << pad << " / \\\n";
    }

    std::cout << pad << "(Touching points: " << touching << ")\n\n";
}

int main() {
    body b(0, 0);
    circle obj(10, 0, 2);
    double bodyX = b.getTorso().getStart().x;
    double targetDistance = 0.5;

    int steps = 0;
    const int MAX_STEPS = 50;

    // Walking
    while (std::abs(bodyX - obj.getCenter().x) > targetDistance && steps < MAX_STEPS) {
        b.walk(0.5, obj.getCenter());
        bodyX = b.getTorso().getStart().x;

        drawScene(b, obj);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        steps++;
    }

    if (steps >= MAX_STEPS) {
        std::cout << "Could not reach object in time.\n";
        return 0;
    }

    // Reaching
    bool grabbed = false;
    for (int i = 0; i < 50 && !grabbed; i++) {
        b.reach(obj.getCenter());
        grabbed = b.catchObject(obj.getCenter());

        drawScene(b, obj);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    if (!grabbed) {
        std::cout << "Failed to grab the object.\n";
    }

    return 0;
}
