#ifndef entity_h
#define entity_h
#include "VArray.h"
#include "PositionClasses.h"
#include "Displayable.h"
#include "FSMStack.h"

// forward declaration
class Spell;
class Board;

class Entity : public Displayable, public Stateful {
private:
    int hp;
    int armor;
    int maxMovePoints;
    int movePoints;

    bool isMoveable;

    Board* boardRef;

    VArray<Spell> spells;
    AbsolutePosition pos;

public:
    Entity(char icon, int hp, int armor, int maxmp, int posx, int posy, bool moveable);
    virtual Entity* clone() = 0;
    virtual ~Entity();

    void setHp(int val);
    void deductHp(int val);
    int getHp();

    void setArmor(int val);
    int getArmor();

    bool canMove();

    void setBoardRef(Board* b);

    void setPos(int px, int py);
    AbsolutePosition getPos();

    void addSpell(Spell spell);
    void removeSpell(int index);
    void executeSpell(int index, Board& board, int dist, Directions facing);
    
    virtual void runState() = 0;

    void kill();
    virtual void onDeath() = 0;
};

#endif