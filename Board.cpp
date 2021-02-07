//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Board.h"
#include "Vec2D.h"
#include "Tile.h"
#include "Entity.h"
#include "EntityClasses.h"
#include "VArray.cpp"

#include <iostream>
#include <stdlib.h> // rand, srand

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

    // display movement
    display();
}

void Board::recursiveMoveEntityAt(Vec2D pos, Vec2D tgt, bool useAxisX) {
    // base case: pos == tgt or next move is invalid
    if(pos == tgt) {
        return;
    }

    // get incremented step for x or y according to diff between pos and tgt
    // this step should move pos towards tgt
    int delta;
    if(useAxisX) {
        delta = pos.x - tgt.x;
    } else {
        delta = pos.y - tgt.y;
    }
    
    if(delta == 0) {
        // no movement on this axis, should jump straight to next recursive call
        recursiveMoveEntityAt(pos, tgt, !useAxisX);
        return;
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

Entity* Board::spawnEntityCopyAt(Vec2D pos, Entity* e) {
    Entity* newEntity = e->clone();
    newEntity->setPos(pos.x, pos.y);
    newEntity->setBoardRef(this);
    spaces->get(pos.y)->get(pos.x)->entity = newEntity;

    if(newEntity->canAct()) {
        actors.push(newEntity);
    }

    return newEntity;
}

void Board::despawnEntityAt(Vec2D pos) {
    Entity *e = spaces->get(pos.y)->get(pos.x)->entity;
    if(e->canAct()) {
        for(int i=0; i<actors.getSize(); i++) {
            if(actors.get(i) == e) {
                actors.remove(i);
                break;
            }
        }
    }

    spaces->get(pos.y)->get(pos.x)->entity = nullptr;
    delete e;
}

Tile* Board::getTileAt(Vec2D pos) {
    return spaces->get(pos.y)->get(pos.x)->tile;
}

void Board::setTileStateAt(Vec2D pos, TileState tileState) {
    Tile *tile = getTileAt(pos);
    if(tile != nullptr) {
        tile->setState(tileState);
    }
}

bool Board::posIsWithinBoard(Vec2D pos) {
    return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
}

bool Board::posIsValidSpawnLocation(Vec2D pos) {
    return posIsWithinBoard(pos) && getEntityAt(pos) == nullptr && getTileAt(pos)->getState() != hole;
}

void Board::display() {
    std::cout << std::endl;
    for(int y=height-1; y>=0; y--) {

        // y-axis numbering
        if(y<=9) {
            std::cout << y;
        } else {
            std::cout << "+";
        }
        // vertical axis divider
        std::cout << " | ";
        
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

    // horizontal axis divider
    std::cout << "----";
    for(int i=0; i<width; i++) {
        std::cout << "--";
    }
    std::cout << std::endl;

    // x-axis numbering
    std::cout << "B | ";
    for(int i=0; i<width; i++) {
        if(i<=9) {
            std::cout << i << " ";
        } else {
            std::cout << "+ ";
        }
    }
    std::cout << std::endl << std::endl;
}

VArray<Vec2D> Board::neighboursForSpaceAt(Vec2D pos) {
    VArray<Vec2D> neighbours;

    // GUARD pos within board
    if(!posIsWithinBoard(pos)) {
        return neighbours;
    }

    Vec2D relPos = Vec2D(0, 1);

    for(int _=0; _<4; _++) {
        if(posIsWithinBoard(relPos + pos) 
        && getEntityAt(relPos + pos) == nullptr
        && getTileAt(relPos + pos)->getState() != hole) {
            neighbours.push(relPos + pos);
        }

        relPos.transformCW90();
    }

    return neighbours;
}

VArray<Entity*> Board::getActors() {
    return actors;
}

Vec2D Board::randomValidPos() {
    srand(time(NULL));
    
    Vec2D pos;
    do {
        int randX = rand()%(width-1);
        int randY = rand()%(height-1);
        pos.updatePosition(randX, randY);
    } while(!posIsValidSpawnLocation(pos));

    return pos;
}

// target methods

VArray<Entity*> Board::getTargets() {
    return targets;
}

void Board::spawnTarget() {
    spawnTarget(randomValidPos());
}

void Board::spawnTarget(Vec2D pos) {
    Target t = Target();
    Entity *newTarget = spawnEntityCopyAt(pos, &t);
    targets.push(newTarget);
}