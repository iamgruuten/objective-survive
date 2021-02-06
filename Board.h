#ifndef board_h
#define board_h
#include "VArray.h"
#include "Vec2D.h"

// Forward declaration
class Entity;
class Tile;

struct Space {
    Entity *entity;
    Tile *tile;
};

class Board {
private:
    int width;
    int height;
    VArray< VArray< Space* >* > *spaces;
public:
    Board(int w, int h);
    ~Board();

    Entity* getEntityAt(Vec2D pos);
    void moveEntityAt(Vec2D origin, Vec2D tgt);
    void spawnEntityCopyAt(Vec2D pos, Entity* e);
    void despawnEntityAt(Vec2D pos);

    Tile* getTileAt(Vec2D pos);
    void setTileAt(Vec2D pos, Tile tile);

    bool posIsWithinBoard(Vec2D pos);
    void display();

    VArray<Vec2D>* neighboursForSpaceAt(Vec2D pos);
};

#endif