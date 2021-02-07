//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Spell

// The Spell is an abstraction of an interaction
// between two entities. It is composed of multiple
// Effects that are applied in sequence during
// execution.

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

    //Deconstructor
    ~Spell();

    //Intialize the spell
    //pre: None
    //Post: None
    Spell(int range);

    //Adds effects to the spell
    //pre: None
    //Post: The new effect is added to the spell
    void addEffect(Effect* effect);
    void activateSpell(Board& board, Vec2D tgtPos, int rotations);
};

#endif