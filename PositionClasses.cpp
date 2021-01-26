#include "PositionClasses.h"
#include <math.h>

// Position implementation

int Position::getL1Distance(Position* a, Position* b) {
    return abs(a->x - b->x) + abs(a->y - b-> y);
};

// RelativePosition implementation

AbsolutePosition RelativePosition::getAbsolutePos(Position origin) {
    return AbsolutePosition(origin.x+x, origin.y+y);
}

// RotationHandler implementation

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

Position RotationHandler::rotated90(Position* tgt, Position* pivot, Rotations dir) {
    Position pos = *tgt;
    rotate90(pos, pivot, dir);
    return pos;
}

Position RotationHandler::rotatedToFace(Position* tgt, Position* pivot, Directions oldDir, Directions newDir) {
    Position pos = *tgt;
    Rotations rot = clockwise;

    // Find n number of clockwise rotations to get oldDir to newDir
    int r = 0; int od = oldDir; int nd = newDir;
    while(od != nd) {
        r ++;
        od = (od+1)%3;
    }

    // Optimise rotation and rotation direction
    if(r > 2) {
        r = 4-r;
        rot = antiClockwise;
    }

    // Do rotations
    for(int i=0; i<r; i++) {
        rotate90(pos, pivot, rot);
    }

    return pos;
}