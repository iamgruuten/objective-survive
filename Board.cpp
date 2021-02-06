//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Board.h"
#include "Vec2D.h"
#include "Tile.h"
#include "Entity.h"
#include "VArray.cpp"

#include <iostream>

// Space implementation
Space::Space() {
    tile = new Tile();
    entity = nullptr;
}

Space::~Space() {
    delete tile;
    if(entity != nullptr) {
        delete entity;
    }
}

Board::Board(int w, int h) {
    width = w;
    height = h;

    spaces = new VArray< VArray< Space* >* >(0, h);
    for(int i=0; i<h; i++) {
        spaces->push(new VArray< Space* >(0, w));
        for(int j=0; j<w; j++) {
            spaces->get(i)->push(new Space());
        }
    }
}

Board::~Board() {
    // Deconstructor
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            delete spaces->get(i)->get(j);
        }
        delete spaces->get(i);
    }
    delete spaces;
}

Entity* Board::getEntityAt(Vec2D pos) {
    // GUARD pos is within board
    if(!posIsWithinBoard(pos)) {
        return NULL;
    }

    return spaces->get(pos.y)->get(pos.x)->entity;
}

void Board::instantMoveEntityAt(Vec2D pos, Vec2D tgt) {
    // move entity to tgt instantly (no checks!)
    Entity *e = getEntityAt(pos);
    spaces->get(pos.y)->get(pos.x)->entity = nullptr;
    spaces->get(tgt.y)->get(tgt.x)->entity = e;
}

void Board::recursiveMoveEntityAt(Vec2D pos, Vec2D tgt, bool useAxisX) {
    // base case: pos == tgt or next move is invalid
    if(pos == tgt) {
        return;
    }

    // get incremented step for x or y according to diff between pos and tgt
    // this step should move pos towards tgt
    int delta = pos.x - tgt.x;
    if(delta == 0) {
        // no movement on this axis, should jump straight to next recursive call
        recursiveMoveEntityAt(pos, tgt, !useAxisX);
    } else if(delta < 0) {
        delta = 1;
    } else {
        delta = -1;
    }

    Vec2D updatedPos = pos;
    if(useAxisX) {
        updatedPos = updatedPos + Vec2D(delta, 0);
    } else {
        updatedPos = updatedPos + Vec2D(0, delta);
    }

    // GUARD target and pos are within board
    if(!posIsWithinBoard(pos) && !posIsWithinBoard(updatedPos)) {
        return;
    }

    // check for collision
    if(getEntityAt(updatedPos) != nullptr) {
        // apply collision to both entities, moving entity stops moving
        return;
    }

    // check for hole
    if(getTileAt(updatedPos)->getState() == hole) {
        // entity drops to death, movement stops as well
        return;
    }

    // checks complete, move to updated pos, repeat recursive move
    instantMoveEntityAt(pos, updatedPos);
    
    // toggles between x and y axis movement
    recursiveMoveEntityAt(updatedPos, tgt, !useAxisX);
}

void Board::spawnEntityCopyAt(Vec2D pos, Entity* e) {
    e->setPos(pos.x, pos.y);
    e->setBoardRef(this);
    spaces->get(pos.y)->get(pos.x)->entity = e->clone();
}

void Board::despawnEntityAt(Vec2D pos) {
    delete spaces->get(pos.y)->get(pos.x)->entity;
}

Tile* Board::getTileAt(Vec2D pos) {
    return spaces->get(pos.y)->get(pos.x)->tile;
}

void Board::setTileStateAt(Vec2D pos, TileState tileState) {
    Tile *tile = spaces->get(pos.y)->get(pos.x)->tile;
    if(tile != nullptr) {
        tile->setState(tileState);
    }
}

bool Board::posIsWithinBoard(Vec2D pos) {
    return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
}

void Board::display() {
    std::cout << width << ", " << height << std::endl;
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            Entity *e = spaces->get(y)->get(x)->entity;
            if(e != nullptr) {
                e->display();
            } else {
                Tile *t = spaces->get(y)->get(x)->tile;
                if(t != nullptr) {
                    t->display();
                } else {
                    std::cout << "█";
                }
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

VArray<Vec2D> Board::neighboursForSpaceAt(Vec2D pos) {
    VArray<Vec2D> neighbours;

    // GUARD pos within board
    if(!posIsWithinBoard(pos)) {
        return neighbours;
    }

    Vec2D relPos = Vec2D(0, 1);

    for(int _=0; _<4; _++) {
        if(posIsWithinBoard(relPos + pos) && getEntityAt(relPos + pos) == nullptr) {
            neighbours.push(relPos + pos);
        }

        relPos.transformCW90();
    }

    return neighbours;
}