#ifndef entity_h
#define entity_h
#include "Displayable.h"
#include "VArray.h"
#include "Position.h"
#include "Spell.h"

class Entity : public Displayable {
private:
    int hp;
    int armor;
    int maxMovePoints;
    int movePoints;
    VArray<Spell> spells;
    Position pos;

public:
    Entity(int posx, int posy);
    Entity(int hp, int armor, int maxmp, int posx, int posy);
    ~Entity();
    void setHp(int val);
    int getHp();
    void setArmor(int val);
    int getArmor();
    void setPos(int px, int py);
    Position getPos();
    void executeSpell(int index);
};

#endif