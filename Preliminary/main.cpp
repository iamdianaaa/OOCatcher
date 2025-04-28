#include "src/point.h"
#include "src/line1.h"
#include "src/line2.h"
#include "src/circle.h"
#include "src/body.h"

#include <iostream>
using namespace std;

int main()
{
    // Test point
    point p1(0, 0);
    point p2(3, 4);
    cout << "Distance: " << p1.dist(p2) << endl; 
    cout << "Direction: " << p1.dir(p2) << endl;

    // Test line1
    line1 l1(p1, p2);
    cout << "Line1 length: " << l1.length() << endl; 

    // Test line2
    line2 l2(p1, p2);
    cout << "Line2 length: " << l2.length() << endl; 

    // Test circle
    circle c1(0, 0, 5);
    cout << "Point in circle: " << c1.contains(p2) << endl; 
    cout << "Point on perimeter: " << c1.on_perimeter(p2) << endl;  

    // Test body
    body b1(0, 10, 10);
    cout << "Neck position: (" << b1.get_neck().get_x() << ", " << b1.get_neck().get_y() << ")" << endl;
    cout << "Back position: (" << b1.get_back().get_x() << ", " << b1.get_back().get_y() << ")" << endl;

    const base_line* arm_left = b1.get_segment(0);
    cout << "Arm Left starts at (" << arm_left->get_x() << ", " << arm_left->get_y() << ")" << endl;

    return 0;
}
