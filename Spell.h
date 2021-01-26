#ifndef spell_h
#define spell_h
#include "VArray.h"
#include "Effect.h"
#include "Position.h"
#include "Direction.h"
#include "Board.h"

class Spell {
private:
    int range;
    VArray<Effect> effects;
public:
    Spell();
    Spell(int r, Direction f, VArray<Effect> e);
    ~Spell();
    void activateSpell(Board& board, int distance, Direction facing, Position origin);
};

#endif