//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef spell_h
#define spell_h
#include "VArray.h"

// forward declaration
class Effect;
class Board;
class Vec2D;

class Spell {
private:
    int range;
    VArray<Effect*>* effects;
public:
    Spell();
    ~Spell();
    Spell(int range);
    void addEffect(Effect* effect);
    void activateSpell(Board& board, Vec2D tgtPos, int rotations);
};

#endif