//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Tile

// The Tile class is an abstraction of a unit area
// in the game environment. Entities 'stand' on these
// and can be affected by the state of the tile when
// moving/being moved over them.

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

    //Set the tile state (0 - Normal, 1 - Hole, 2 - Water)
    //pre: None
    //Post: The new state is set the tile
    void setState(TileState tileState);

    //Retrieve the state of the tiles
    //pre: None
    //Post: None
    TileState getState();
    int movementCostForTile();

    //Displays all tiles 
    //pre: None
    //Post: None
    void display();
};

#endif