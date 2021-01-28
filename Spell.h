#ifndef spell_h
#define spell_h
#include "VArray.h"

// forward declaration
class Effect;
class Board;
enum Directions: int;
class AbsolutePosition;

class Spell {
private:
    int range;
    VArray<Effect*> effects;
public:
    Spell();
    Spell(int range) : range(range), effects() {}
    void addEffect(Effect* effect);
    void activateSpell(Board& board, int distance, Directions facing, AbsolutePosition origin);
};

#endif