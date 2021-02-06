//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef pathfinder_h
#define pathfinder_h
#include <string>
#include "VArray.h"

// Forward declaration
class Vec2D;
class Board;
enum TileState: int;

class Pathfinder {
private:
public:
    virtual ~Pathfinder();
    virtual int getScoreForTileState(TileState tileState) = 0;
    VArray<Vec2D> getPathToTarget(Board& b, Vec2D startPos, Vec2D tgtPos);
};

#endif