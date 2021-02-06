//Team members - Lee Quan Sheng and Eugene Long
//Group 8

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

public:
    Board(int w, int h);
    ~Board();

    Entity* getEntityAt(Vec2D pos);
    void instantMoveEntityAt(Vec2D pos, Vec2D tgt);
    void recursiveMoveEntityAt(Vec2D pos, Vec2D tgt, bool useAxisX);
    void spawnEntityCopyAt(Vec2D pos, Entity* e);
    void despawnEntityAt(Vec2D pos);

    Tile* getTileAt(Vec2D pos);
    void setTileStateAt(Vec2D pos, TileState tileState);

    bool posIsWithinBoard(Vec2D pos);
    void display();

    VArray<Vec2D> neighboursForSpaceAt(Vec2D pos);
    VArray<Entity*> getActors();
    Vec2D randomValidPos();
};

#endif