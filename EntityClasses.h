//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// ! Featured !
// Heuristic Function AI

// Entity Classes

// These Classes inherit the Entity specifications
// and represent more specialised instances of the
// Entity class.

// There is currently a Ranged Entity Class that
// has been partly implemented, and is unfortunately
// non-operational.

// However, it is an example of a entity that uses
// a heuristic function in deciding the next move to take.

 
#ifndef EntityClasses_h
#define EntityClasses_h

#include "Entity.h"
#include "Pathfinder.h"

class Walls : public Entity{
public:
    Walls();
    Walls(int hp, int armor);
    ~Walls();
    Entity* clone();
    void runState();
    void display();
};


class Melee : public Entity, public Pathfinder {
public:
    Melee();
    Melee(int hp, int armor, int maxmp);
    ~Melee();
    Entity* clone();
    void runState();
    void display();
    int getScoreForTileState(TileState tileState);
    int getScoreForPosition(Vec2D pos);
};


class Ranged : public Entity, public Pathfinder {
public:
    Ranged();
    Ranged(int hp, int armor, int maxmp);
    ~Ranged();
    Entity* clone();
    void runState();
    void display();
    int getScoreForTileState(TileState tileState);
    int getScoreForPosition(Vec2D pos);
};

class Target : public Entity {
public:
    Target();
    Target(int hp, int armor);
    ~Target();
    Entity* clone();
    void runState();
    void display();
};

#endif  
