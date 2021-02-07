//Team members - Lee Quan Sheng and Eugene Long
//Group 8

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