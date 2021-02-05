#include "Tile.h"
#include "FSMStack.h"
#include <string>

Tile::Tile() : Stateful() {
    setIcon('.');
}

Tile::~Tile() {}

void Tile::runState() {}

TileState Tile::getState() {
    std::string state = fsmStack.getTopState();
    if(state == "normal") { return normal; }
    else if (state == "hole") { return hole; }
    else { return water; }
}

void Tile::pushState(TileState tileState) {
    switch(tileState) {
        case normal:
            fsmStack.pushState("normal");
            break;
        case hole:
            fsmStack.pushState("hole");
            break;
        case water:
            fsmStack.pushState("water");
            break;
    }
}