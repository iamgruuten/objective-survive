#ifndef pathfinder_h
#define pathfinder_h
#include <string>
#include "VArray.h"

// Forward declaration
class AbsolutePosition;
enum TileState: int;

class Pathfinder {
private:
public:
    virtual ~Pathfinder();
    virtual int getScoreForTileState(TileState tileState) = 0;
    VArray<AbsolutePosition> getPathToTarget(AbsolutePosition tgtPos);
};

#endif