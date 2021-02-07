//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Effect Classes

// Effects are the most basic components of a Spell
// They abstract interactions with the game environment
// In this case, although only damage and knockback are
// currently represented, they can act directly on any 
// of an entitiy's attributes.

#ifndef effectclasses_h
#define effectclasses_h
#include "Vec2D.h"

// forward declaration
class Board;

class Effect {
protected:
    Vec2D relPos;
public:
    Effect(int relX, int relY) : relPos(Vec2D(relX, relY)) {}
    virtual ~Effect();
    virtual void applyEffect(Board& b, Vec2D tgtPos, int rotations) = 0;
};

class DamageMoveEffect : public Effect {
private:
    int damage;
    Vec2D knockbackVec;
public:
    DamageMoveEffect(int relX, int relY, int dmg, Vec2D knockback) : Effect(relX, relY), damage(dmg), knockbackVec(knockback) {}
    ~DamageMoveEffect();
    void applyEffect(Board& b, Vec2D tgtPos, int rotations);
};

#endif