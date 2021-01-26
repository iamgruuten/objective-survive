#include "Position.h"
#include <iostream>

int main() {
    Position p1 = Position(0, 0);   
    Position p2 = Position(3, 3);
    std::cout << p1.getDistanceFrom(p2) << std::endl;
    return 0;
}