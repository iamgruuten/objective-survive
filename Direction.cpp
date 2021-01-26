#include "Direction.h"
#include "Position.cpp"

DirectionVector::DirectionVector() {
    magnitude = 0;
    direction = up;
}

DirectionVector::DirectionVector(int mag, Direction dir) {
    magnitude = mag;
    direction = dir;
}

DirectionVector::~DirectionVector() {}

/*
int min(int a, int b) {
    if(a <= b) { return a; } else { return b; }
}

int max(int a, int b) {
    if(a >= b) { return a; } else { return b; }
}
*/

Position DirectionVector::getAbsolutePos(Position origin) {
    int x = origin.x;
    int y = origin.y;

    switch(direction) {
        case up:
            return Position(x, y+magnitude);
        case right:
            return Position(x+magnitude, y);
        case down:
            return Position(x, y-magnitude);
        case left:
            return Position(x-magnitude, y);
    }
}

/*
Position DirectionVector::getBoundedPos(int minX, int minY, int maxX, int maxY, Position origin) {
    int x = origin.x;
    int y = origin.y;

    switch(direction) {
        case up:
            return Position(maxX, min(y+magnitude, maxY));
        case right:
            return Position(min(x+magnitude, maxX), y);
        case down:
            return Position(x, max(y-magnitude, minY));
        case left:
            return Position(max(x-magnitude, minX), y);
    }
}
*/