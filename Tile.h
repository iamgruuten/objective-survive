//Team members - Lee Quan Sheng and Eugene Long
//Group 8
//This class implementation is to create tiles for the space that is intialize 

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

    //Displays all tiles 
    //pre: None
    //Post: None
    void display();
};

#endif