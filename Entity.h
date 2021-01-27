#ifndef entity_h
#define entity_h
#include "VArray.h"
#include "PositionClasses.h"
#include "Displayable.h"
#include "FSMStack.h"

// forward declaration
class Spell;

class Entity : public Displayable, public Stateful {
private:
    int hp;
    int armor;
    int maxMovePoints;
    int movePoints;
    VArray<Spell> spells;
    AbsolutePosition pos;

public:
    Entity(char icon, int hp, int armor, int maxmp, int posx, int posy);
    void setHp(int val);
    int getHp();
    void setArmor(int val);
    int getArmor();
    void setPos(int px, int py);
    AbsolutePosition getPos();
    void executeSpell(int index);
    virtual void runState();
};

#endif