#ifndef tile_h
#define tile_h
#include <string>
#include "Displayable.h"
#include "FSMStack.h"

//Configuration
enum TileState: int {
    normal = 0, hole = 1, water = 2
};

class Tile : public Displayable {
private:
    TileState state;
public:
    Tile();
    ~Tile();
    void setState(TileState tileState);
    TileState getState();

    void display();
};

#endif