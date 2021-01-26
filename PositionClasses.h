#ifndef positionclasses_h
#define positionclasses_h

enum Rotations : int {
    antiClockwise = -1, clockwise = 1
};
enum Directions : int {
    up = 0, right = 1, down = 2, left = 3
};

class Position { 
public:
    Position(int x, int y) : x(x), y(y) {}
    Position(const Position &pos) : x(pos.x), y(pos.y) {}
    int x;
    int y;
    int getL1Distance(Position* a, Position* b);
};

class AbsolutePosition : private Position {
private:
public:
    AbsolutePosition(int x, int y) : Position(x, y) {}
};

class RelativePosition : private Position {
private:
public:
    RelativePosition(int x, int y) : Position(x, y) {};
    AbsolutePosition getAbsolutePos(Position origin);
};

class RotationHandler {
private:
public:
    friend class Position;
    void rotate90(Position& tgt, Position* pivot, Rotations dir);
    Position rotated90(Position* tgt, Position* pivot, Rotations dir);
    Position rotatedToFace(Position* tgt, Position* pivot, Directions oldDir, Directions newDir);
};

#endif