//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Board

// The Board Class is an abstrction for the game's environment
// It contains spaces, which represent a unit area of the board
// These spaces can contain entities and tiles, of which the 
// entities represent game pieces and tiles represent the board
// segments.

#ifndef board_h
#define board_h
#include "VArray.h"
#include "Vec2D.h"
#include "Tile.h"

// Forward declaration
class Entity;

struct Space {
    Entity *entity;
    Tile *tile;

    Space();
    ~Space();
};

class Board {
private:
    int width;
    int height;
    VArray< VArray< Space* >* > *spaces;
    VArray<Entity*> actors;
    VArray<Entity*> targets;

public:
    Board(int w, int h);
    ~Board();

    Entity* getEntityAt(Vec2D pos);
    void instantMoveEntityAt(Vec2D pos, Vec2D tgt);
    void recursiveMoveEntityAt(Vec2D pos, Vec2D tgt, bool useAxisX);
    Entity* spawnEntityCopyAt(Vec2D pos, Entity* e);
    void despawnEntityAt(Vec2D pos);

    Tile* getTileAt(Vec2D pos);
    void setTileStateAt(Vec2D pos, TileState tileState);

    bool posIsWithinBoard(Vec2D pos);
    bool posIsValidSpawnLocation(Vec2D pos);
    bool posIsValidPathingLocation(Vec2D pos);
    void display();

    VArray<Vec2D> neighboursForSpaceAt(Vec2D pos);
    VArray<Entity*> getActors();
    Vec2D randomValidSpawnPos();

    VArray<Entity*> getTargets();
    void spawnTarget();
    void spawnTarget(Vec2D pos);

    void runActors();
};

#endif