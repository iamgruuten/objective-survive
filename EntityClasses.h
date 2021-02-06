 #ifndef EntityClasses_h
 #define EntityClasses_h

#include "Entity.h"

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


class Melee : public Entity{
public:
    Melee();
    Melee(int hp, int armor, int maxmp, bool moveable);
    ~Melee();
    Entity* clone();
    void runState();
    void display();
    void onDeath();
};


class Ranged : public Entity{
    Ranged();
    Ranged(int hp, int armor, int maxmp, bool moveable);
    ~Ranged();
    Entity* clone();
    void runState();
    void display();
    void onDeath();
};

#endif  
