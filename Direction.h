#ifndef directionvector_h
#define directionvector_h
#include "Position.h"

enum Direction: int {
    up = 0, right = 1, down = 2, left = 3
};

class DirectionVector {
private:
    int magnitude;
    Direction direction;
public:
    DirectionVector();
    DirectionVector(int mag, Direction dir);
    ~DirectionVector();
    Position getAbsolutePos(Position origin);
    //Position getBoundedPos(int minX, int minY, int maxX, int maxY, Position origin);
};

#endif