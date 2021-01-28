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
    int x;
    int y;
    
    Position(int x, int y) : x(x), y(y) {}
    Position(const Position &pos) : x(pos.x), y(pos.y) {}
    Position(Directions dir, int magnitude);
    int getL1Distance(Position* a, Position* b);
    void updatePosition(int x, int y);
    void movePosition(Directions dir);
};

class AbsolutePosition : public Position {
private:
public:
    AbsolutePosition(int x, int y) : Position(x, y) {}
};

class RelativePosition : public Position {
private:
public:
    RelativePosition(int x, int y) : Position(x, y) {};
    RelativePosition(Directions dir, int magnitude) : Position(dir, magnitude) {};
    AbsolutePosition getAbsolutePos(Position origin);
};

class RotationHandler {
private:
public:
    friend class Position;
    static void maintainRelativeDirection(Directions& tgt, Directions reference, Directions newDir);
    static void rotate90(Position& tgt, Position* pivot, Rotations dir);
    static void rotateToFace(Position& tgt, Position* pivot, Directions oldDir, Directions newDir);
    static Position rotated90(Position* tgt, Position* pivot, Rotations dir);
    static Position rotatedToFace(Position* tgt, Position* pivot, Directions oldDir, Directions newDir);
};

#endif