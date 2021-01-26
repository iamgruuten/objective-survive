#include "Board.h"
#include "Entity.h"
#include <iostream>

// Space implementation

void Space::display() {
    if(entity != NULL) {
        entity->display();
    } else {
        tile.display();
    }
}

Entity& Space::getEntity() {
    return *entity;
}

void Space::setEntity(Entity *e) {
    entity = e;
}

Entity* Space::popEntity() {
    Entity* tmp = entity;
    entity = nullptr;
    return tmp;
}

void Space::moveEntity(Space& s) {
    s.entity = entity;
    entity = nullptr;
}

Tile& Space::getTile() {
    return tile;
}

// Board implementation

Board::Board(int size) {
    overlayEnabled = false;
    grid = VArray< VArray<Space> >(size);
    overlay = VArray< VArray<char> >(size);

    // initialise tiles
    for(int i=0; i<size; i++) {
        grid.push(VArray<Space>(size));
        overlay.push(VArray<char>(size));
        for(int j=0; j<size; j++) {
            grid.get(i).push(Space());
            overlay.get(i).push(' ');
        }
    }
}

void Board::resetOverlay() {
    for(int i=0; i<overlay.getSize();i++) {
        for(int j=0; j<overlay.get(i).getSize();j++) {
            overlay.get(i).set(' ', j);
        }
    }
}

void Board::enableOverlay() {
    overlayEnabled = true;
}

void Board::disableOverlay() {
    overlayEnabled = false;
}

void Board::display() {
    if(overlayEnabled) {
        for(int i=0; i<overlay.getSize();i++) {
            for(int j=0; j<overlay.get(i).getSize();j++) {
                std::cout << overlay.get(i).get(j) << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for(int i=0; i<grid.getSize();i++) {
            for(int j=0; j<grid.get(i).getSize();j++) {
                grid.get(i).get(j).display();
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
}

bool Board::checkPosWithinBoard(AbsolutePosition pos) {
    return pos.x >= 0 && pos.x < size && pos.y >= 0 && pos.y < size;
}

Entity* Board::getEntityAt(AbsolutePosition pos) {
    if(checkPosWithinBoard(pos) == false) {
        return NULL;
    }

    return &grid.get(pos.x).get(pos.y).getEntity();
}

Tile* Board::getTileAt(AbsolutePosition pos) {
    if(checkPosWithinBoard(pos) == false) {
        return NULL;
    }
    
    return &grid.get(pos.x).get(pos.y).getTile();
}