//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// ! Featured !

// Pathfinder

// The Pathfinder class is a component class
// that can be inherited to utilise motion
// planning methods.

// The getPathToTarget method uses the A* Algorithm
// to obtain a path to a specified position.

// To complement it, a heuristic function based
// on the Manhattan (L1) distance between tiles
// is used.

#ifndef pathfinder_h
#define pathfinder_h
#include <string>
#include "VArray.h"
#include "BHPriorityQueue.h"

// Forward declaration
class Vec2D;
class Board;
enum TileState: int;

class Pathfinder {
private:
public:
    virtual ~Pathfinder();
    virtual int getScoreForTileState(TileState tileState) = 0;
    virtual int getScoreForPosition(Vec2D pos) = 0;
    VArray<Vec2D> getPathToTarget(Board* b, Vec2D startPos, Vec2D tgtPos);
    void recursiveSearchMoves(Board& b, int mp, Vec2D pos, BHPriorityQueue<Vec2D>& posScores);
    Vec2D bestMoveForUnit(Board& b, int mp, Vec2D pos);
};

#endif