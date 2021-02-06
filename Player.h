#ifndef player_h
#define player_h
#include "Entity.h"

class Player : public Entity {
private:
public:
    Player(int hp, int armor, int maxmp, int posx, int posy);
    ~Player();
};

#endif