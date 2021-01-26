#include "Board.h"
#include "VArray.cpp"
#include "Entity.cpp"
#include "Background.cpp"
#include "Displayable.cpp"
#include "Position.cpp"
#include <iostream>

// Tile implementations
Tile::Tile() {
    overlay = ' ';
    background = Background(plain);
    foreground = NULL;
}

Tile::~Tile() {}

Entity* Tile::getForeground() {
    return foreground;
}

Background& Tile::getBackground() {
    return background;
}

void Tile::setOverlay(char icon) {
    overlay = icon;
}

void Tile::clearOverlay() {
    overlay = ' ';
}

void Tile::enteredForeground(Entity* entity) {
    foreground = entity;
}

void Tile::leftForeground() {
    foreground = NULL;
}

void Tile::setBackground(Background bg) {
    background = bg;
}

void Tile::display() {
    if(foreground != NULL) {
        foreground->display();
    } else {
        background.display();
    }
}

void Tile::displayOverlay() {
    if(overlay == ' ') {
        display();
    } else {
        std::cout << overlay;
    }
}

// Board implementations
Board::Board(int size) {
    showOverlay = false;
    grid = VArray< VArray<Tile> >(size);

    // initialise tiles
    for(int i=0; i<size; i++) {
        grid.push(VArray<Tile>(size));
        for(int j=0; j<size; j++) {
            grid.get(i).push(Tile());
        }
    }
}

Board::~Board() {}

Entity* Board::getEntityAt(Position pos) {
    return grid.get(pos.x).get(pos.y).getForeground();
}

Background& Board::getBackgroundAt(Position pos) {
    return grid.get(pos.x).get(pos.y).getBackground();
}

void Board::enableOverlay() {
    showOverlay = true;
}

void Board::disableOverlay() {
    showOverlay = false;
}

void Board::resetOverlay() {
    for(int i=0; i<grid.getSize();i++) {
        for(int j=0; j<grid.get(i).getSize();j++) {
            grid.get(i).get(j).clearOverlay();
        }
    }
}

void Board::display() {
    for(int i=0; i<grid.getSize();i++) {
        for(int j=0; j<grid.get(i).getSize();j++) {
            if(showOverlay == true) {
                grid.get(i).get(j).displayOverlay();
            } else {
                grid.get(i).get(j).display();
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

