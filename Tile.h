#ifndef tile_h
#define tile_h
#include <string>
#include "Displayable.h"
#include "FSMStack.h"

//Configuration
enum TileState: int {
    normal = 0, hole = 1, water = 2
};

class Tile : public Displayable, public Stateful {
private:
public:
    Tile();
    ~Tile();
    void runState();
    TileState getState();
    void pushState(TileState tileState);
};

#endif