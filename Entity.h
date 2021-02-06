#ifndef entity_h
#define entity_h
#include "VArray.h"
#include "Vec2D.h"
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

    VArray<Spell>* spells;
    Vec2D pos;

public:
    Entity(int hp, int armor, int maxmp, bool moveable);
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
    Vec2D getPos();

    void addSpell(Spell spell);
    void removeSpell(int index);

    // executest the spell at the index at (tgtPos) on the board, with all effect relative positions and directed effects rotated by (rotations)
    // negative rotations indicate a 90  degree counter-clockwise rotation, while positive rotations are 90 degrees clockwise.
    void executeSpell(int index, Board& board, Vec2D tgtPos, int rotations);
    
    virtual void runState() = 0;
    virtual void display() = 0;

    void kill();
    virtual void onDeath() = 0;
};

class Walls : public Entity{
    private:
        int hp;
        int armor;
        int thorn;
        
        bool isMoveable;
    public:
        void setUp();
        void deductHp(int hp);
};

#endif