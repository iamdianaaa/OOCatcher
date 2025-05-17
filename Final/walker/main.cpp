#include "oocatcher.h"

int main() {
    body b(0, 0);
    circle obj(10, 0, 2);

    oocatcher catcher(b, obj);
    catcher.run();

    return 0;
}
