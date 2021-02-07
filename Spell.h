//Team members - Lee Quan Sheng and Eugene Long
//Group 8
//This class implementation is to create spell that is currently used by ranged units 

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