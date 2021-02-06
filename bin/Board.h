#ifndef board_h
#define board_h
#include "VArray.h"
#include "Tile.h"

// forward declaration
class Entity;
class AbsolutePosition;

class Space {
private:
    Entity* entity;
    Tile tile;
public:
    Space();
    ~Space();
    void display();

    // Entity related methods
    Entity* getEntity();
    void setEntity(Entity *e);
    Entity* popEntity();
    void moveEntity(Space& s);

    // Tile related methods
    Tile& getTile();
};

class Board {
private:
    int size;
    bool overlayEnabled;
    VArray< VArray<char>* > *overlay;
    VArray< VArray<Space*>* > *grid;
public:
    Board(int size);
    void resetOverlay();
    void enableOverlay();
    void disableOverlay();
    void display();

    bool checkPosWithinBoard(AbsolutePosition pos);

    Entity* getEntityAt(AbsolutePosition pos);
    void spawnEntityCopyAt(Entity* e, AbsolutePosition pos);
    void despawnEntityAt(AbsolutePosition pos);
    void moveEntity(AbsolutePosition epos, AbsolutePosition tgtpos);

    Tile* getTileAt(AbsolutePosition pos);
    VArray<AbsolutePosition>* getNeighboursForSpaceAt(AbsolutePosition pos);
};

#endif