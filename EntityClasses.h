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
    void onDeath();
};


class Melee : public Entity, public Pathfinder {
public:
    Melee();
    Melee(int hp, int armor, int maxmp);
    ~Melee();
    Entity* clone();
    void runState();
    void display();
    void onDeath();
    int getScoreForTileState(TileState tileState);
};


class Ranged : public Entity{
public:
    Ranged();
    Ranged(int hp, int armor, int maxmp);
    ~Ranged();
    Entity* clone();
    void runState();
    void display();
    void onDeath();
};

#endif  
