#include "Tile.h"
#include "FSMStack.h"

Tile::Tile() : Stateful() {
    setIcon('.');
}

Tile::~Tile() {}

void Tile::runState() {
    // TODO: implement fsm
}