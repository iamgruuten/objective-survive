#ifndef spell_h
#define spell_h
#include "VArray.h"

// forward declaration
class Effect;
class Board;
class Direction;
class Position;

class Spell {
private:
    int range;
    VArray<Effect*> effects;
public:
    Spell(int range);
    void addEffect(Effect);
    void activateSpell(Board& board, int distance, Direction facing, Position origin);
};

#endif