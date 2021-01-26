#ifndef position_h
#define position_h
#include "Direction.h"

class Position {
private:
public:
    int x;
    int y;

    Position();
    Position(int x, int y);
    ~Position();
    int getDistanceFrom(Position pos);
};

class RelativePosition {
private:
public:
    int x;
    int y;

    RelativePosition();
    RelativePosition(int x, int y);
    ~RelativePosition();
    RelativePosition rotated(Direction oldDir, Direction newDir);

    // static methods
    static Position getAbsolutePos(Position origin, RelativePosition relPos);
};

#endif