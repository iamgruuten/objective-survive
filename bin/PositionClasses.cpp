#include "PositionClasses.h"
#include <math.h>

// Position implementation

Position::Position(Directions dir, int magnitude) {
    this-> x = 0; this->y = 0;
    switch(dir) {
        case up:
            this->y = magnitude;
        case right:
            this->x = magnitude;
        case down:
            this->y = -magnitude;
        case left:
            this->x = -magnitude;
    }
} 

int Position::getL1Distance(Position* a, Position* b) {
    return abs(a->x - b->x) + abs(a->y - b-> y);
};

void Position::updatePosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::movePosition(Directions dir) {
    switch(dir) {
        case up:
            this->y ++;
        case right:
            this->x ++;
        case down:
            this->y --;
        case left:
            this->x --;
    }
}

bool Position::operator==(Position rhs) {
    return x == rhs.x && y == rhs.y;
}

// RelativePosition implementation

AbsolutePosition RelativePosition::getAbsolutePos(Position origin) {
    return AbsolutePosition(origin.x+x, origin.y+y);
}

// RotationHandler implementation

int getClockwiseRotationDifference(Directions oldDir, Directions newDir) {
    int r = 0; int od = oldDir; int nd = newDir;
    while(od != nd) {
        r ++;
        od = (od+1)%4;
    }
    return r;
}

void RotationHandler::maintainRelativeDirection(Directions& tgt, Directions reference, Directions newDir) {
    // Find n number of clockwise rotations to get oldDir to newDir
    int r = getClockwiseRotationDifference(reference, newDir);

    // get corresponding direction number
    int dir = (tgt+r)%4;

    // convert int to direction enum and update tgt
    switch(dir) {
        case 0:
            tgt = up;
            break;
        case 1:
            tgt = right;
            break;
        case 2:
            tgt = down;
            break;
        case 3:
            tgt = left;
            break;
    }
}

void RotationHandler::rotate90(Position& tgt, Position* pivot, Rotations dir) {
    int x, y;
    switch(dir) {
        case antiClockwise:
            x = -tgt.y+pivot->x;
            y = tgt.x+pivot->y;
            tgt.x = x;
            tgt.y = y;
            break;
        case clockwise:
            x = tgt.y+pivot->x;
            y = -tgt.x+pivot->y;
            tgt.x = x;
            tgt.y = y;
    }
}

void RotationHandler::rotateToFace(Position& tgt, Position* pivot, Directions oldDir, Directions newDir) {
    Rotations rot = clockwise;

    // Find n number of clockwise rotations to get oldDir to newDir
    int r = getClockwiseRotationDifference(oldDir, newDir);

    // Optimise rotation and rotation direction
    if(r > 2) {
        r = 4-r;
        rot = antiClockwise;
    }

    // Do rotations
    for(int i=0; i<r; i++) {
        rotate90(tgt, pivot, rot);
    }
}

Position RotationHandler::rotated90(Position* tgt, Position* pivot, Rotations dir) {
    Position pos = *tgt;
    rotate90(pos, pivot, dir);
    return pos;
}

Position RotationHandler::rotatedToFace(Position* tgt, Position* pivot, Directions oldDir, Directions newDir) {
    Position pos = *tgt;
    rotateToFace(pos, pivot, oldDir, newDir);
    return pos;
}