#include "body.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

const int scale = 2;
const int width = 80;

void drawSceneThrow(const Body& b, const Point& snowball, const Point& target, bool isThrowing, bool showHit = false) {
    int ballX = static_cast<int>(snowball.x * scale);
    int targetX = static_cast<int>(target.x * scale);
    int bodyX = static_cast<int>(b.getArmR().getStart().x * scale);

    std::string pad(bodyX, ' ');

    for (int i = 0; i < width; ++i) {
        if (showHit && i == ballX && i == targetX)
            std::cout << "X";
        else if (i == ballX)
            std::cout << "o";
        else if (i == targetX)
            std::cout << "T";
        else
            std::cout << " ";
    }
    std::cout << "\n";

    if (isThrowing) {
        std::cout << pad << " \\o/ \n";
        std::cout << pad << "  |  \n";
    } else {
        std::cout << pad << "  o  \n";
        std::cout << pad << " /|\\ \n";
    }

    std::cout << pad << " / \\ \n";
    std::cout << "\n";
}

int main() {
    Body b(0, 4);
    Point target(10, 5);
    double radius = 3.0;

    b.aimArmAt(target);

    Point origin = b.getArmR().getEnd();
    Point dir = target - origin;
    double norm = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    Point velocity = dir * (10.0 / norm);

    Point snowball = origin;

    const double timeStep = 0.1;
    const int maxFrames = 60;

    bool isThrowing = true;

    for (int i = 0; i < maxFrames; ++i) {
        int ballX = static_cast<int>(snowball.x * scale);
        int targetX = static_cast<int>(target.x * scale);

        if (ballX == targetX) {
            drawSceneThrow(b, snowball, target, false, true);
            std::cout << "Target hit!\n";
            break;
        }

        drawSceneThrow(b, snowball, target, isThrowing);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        snowball = snowball + velocity * timeStep;

        isThrowing = false;
    }

    return 0;
}
