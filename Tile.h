#ifndef tile_h
#define tile_h
#include "Displayable.h"
#include "Runnable.h"
#include "FSMStack.h"

class Tile : public Displayable, public Stateful {
private:
public:
    Tile();
    void tick();
};

#endif