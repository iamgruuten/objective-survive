#include "Position.h"
#include "Direction.cpp"
#include <math.h>

// Position implementation
Position::Position() {
    x = 0;
    y = 0;
}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::~Position() {}

int Position::getDistanceFrom(Position pos) {
    // pythogoras theorem a^2 + b^2 = c^2; c = sqrt(a^2+b^2)
    return (int) sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
}

// RelativePosition implementation
RelativePosition::RelativePosition() {
    x = 0;
    y = 0;
}

RelativePosition::RelativePosition(int x, int y) {
    this->x = x;
    this->y = y;
}

RelativePosition::~RelativePosition() {}

Position RelativePosition::getAbsolutePos(Position origin, RelativePosition relPos) {
    return Position(origin.x + relPos.x, origin.y + relPos.y);
}

RelativePosition RelativePosition::rotated(Direction oldDir, Direction newDir) {
    int rotations = abs(newDir - oldDir);
    int relx = x;
    int rely = y;

    // rotate point about 0, 0 first.
    for(int i=0; i<rotations; i++) {
        int tmp = relx;
        relx = -rely;
        rely = tmp;
    }

    return RelativePosition(relx, rely);
}