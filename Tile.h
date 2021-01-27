#ifndef tile_h
#define tile_h
#include "Displayable.h"
#include "FSMStack.h"

class Tile : public Displayable, public Stateful {
private:
public:
    Tile();
    ~Tile();
    void runState();
};

#endif