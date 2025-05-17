#include <iostream>
#include "body.h"

int main() {
    Body b(0, 4);

    Point target(10, 5);
    double radius = 3.0;

    b.aimArmAt(target);

    b.throwSnowball(target, radius);

    return 0;
}
