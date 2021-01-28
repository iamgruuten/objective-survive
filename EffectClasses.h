#ifndef effectclasses_h
#define effectclasses_h
#include "PositionClasses.h"

// forward declaration
class Board;

class Effect {
protected:
    RelativePosition relPos;
public:
    Effect(int relX, int relY) : relPos(RelativePosition(relX, relY)) {}
    virtual void applyEffect(Board& b, AbsolutePosition tgtPos, Directions facing) = 0;
};

class DamageMoveEffect : private Effect {
private:
    int damage;
    int tiles;
    Directions facing;
public:
    DamageMoveEffect(int relX, int relY, int dmg, int tiles, Directions facing) : Effect(relX, relY), damage(dmg), tiles(tiles) {}
    void applyEffect(Board& b, AbsolutePosition tgtPos, Directions newFacing);
};

#endif