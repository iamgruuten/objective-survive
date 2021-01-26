#ifndef tile_h
#define tile_h
#include "Displayable.h"
#include "Runnable.h"
#include "FSMStack.h"

class Tile : private Displayable, private Runnable, private Stateful {
private:
public:
    Tile(char icon);
    void tick();
};

#endif