//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Tile.h"
#include "FSMStack.h"
#include <string>
#include <iostream>

Tile::Tile() {
    state = normal;
}

Tile::~Tile() {}

void Tile::setState(TileState tileState) {
    state = tileState;
}

TileState Tile::getState() {
    return state;
}

void Tile::display() {
    switch(state) {
        case normal:
            std::cout << ".";
            break;
        case hole:
            std::cout << " ";
            break;
        case water:
            std::cout << "w";
            break;
    }
}

int Tile::movementCostForTile() {
    switch(state) {
        case normal: return 1;
        case hole: return 999;
        case water: return 2;
    }
}