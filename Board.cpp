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

//Implementation of space in board to store tile and entity
//pre: None
//Post: None
Space::Space() {
    tile = new Tile();
    entity = nullptr;
}

//Deconstructor of space in board to deconstruct tile and entity
//pre: None
//Post: None
Space::~Space() {
    delete tile;
    if(entity != nullptr) {
        delete entity;
    }
}

//Initialization of the board with 
//pre: Passing coords must not go beyond board size
//Post: New Space is insert to board
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

//Deconstructor of board
//Pre: None
//Post: Deletes board from memory
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

//Gets entity indicate postion from board
//pre: Position must exist in the board
//Post: None 
Entity* Board::getEntityAt(Vec2D pos) {
    // GUARD pos is within board
    if(!posIsWithinBoard(pos)) {
        return NULL;
    }

    return spaces->get(pos.y)->get(pos.x)->entity;
}

//Move entity to a different position instantly without checking
//pre: Position must exist in the board
//Post: The entity from existing position is deleted, and new entity is insert to updated position
void Board::instantMoveEntityAt(Vec2D pos, Vec2D tgt) {
    // move entity to tgt instantly (no checks!)
    Entity *e = getEntityAt(pos);
    spaces->get(pos.y)->get(pos.x)->entity = nullptr;
    spaces->get(tgt.y)->get(tgt.x)->entity = e;

    //update entity pos
    e->setPos(tgt.x, tgt.y);

    // display movement
    display();
}

//Move entity to a different position recursively with checking
//pre: Position must exist in the board
//Post: The entity from existing position is deleted, and new entity is insert to updated position
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

//Spawn entity in space that is initialized
//pre: Space must exist in the indicated position
//Post: A new entity is insert to the space that is in the board position
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

//Delete entity from board
//pre: Entity must exist in the space
//Post: The entity is removed from the space that is in the board position
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

//Get the tile type from the space position
//pre: Tile must exist in the space
//Post: None
Tile* Board::getTileAt(Vec2D pos) {
    return spaces->get(pos.y)->get(pos.x)->tile;
}

//Set the tile type on the space position
//pre: Tile must not exist in the space
//Post: The new tile state is insert to the space that is in the board position
void Board::setTileStateAt(Vec2D pos, TileState tileState) {
    Tile *tile = getTileAt(pos);
    if(tile != nullptr) {
        tile->setState(tileState);
    }
}

//Checks if position is within the board
//pre: None
//Post: None
bool Board::posIsWithinBoard(Vec2D pos) {
    return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
}

//Checks if position is able to spawn in the indicate location
//pre: None
//Post: None
bool Board::posIsValidSpawnLocation(Vec2D pos) {
    return posIsWithinBoard(pos) && getEntityAt(pos) == nullptr && getTileAt(pos)->getState() != hole;
}


bool Board::posIsValidPathingLocation(Vec2D pos) {
    return posIsWithinBoard(pos) && (getEntityAt(pos) == nullptr || getEntityAt(pos)->canBePathed()) && getTileAt(pos)->getState() != hole;
}

//Display board
//pre: None
//Post: None
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

//Obtain the valid neighbouring locations on the around the indicated position 
//pre: Space must exist in the board position
//Post: None
VArray<Vec2D> Board::neighboursForSpaceAt(Vec2D pos) {
    VArray<Vec2D> neighbours;

    // GUARD pos within board
    if(!posIsWithinBoard(pos)) {
        return neighbours;
    }

    Vec2D relPos = Vec2D(0, 1);

    for(int _=0; _<4; _++) {
        if(posIsValidPathingLocation(relPos + pos)) {
            neighbours.push(relPos + pos);
        }

        relPos.transformCW90();
    }

    return neighbours;
}

//Get All Actors
//pre: None
//Post: None
VArray<Entity*> Board::getActors() {
    return actors;
}

//Random spawn units (Entity) in a valid position
//pre: None
//Post: Insert entity to space in the position
Vec2D Board::randomValidSpawnPos() {
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

//Retrieve all targets (Entity) in the board
//pre: The position must have a space intialize
//Post: None
VArray<Entity*> Board::getTargets() {
    return targets;
}

//Spawn target at a random position
//pre: None
//Post: None
void Board::spawnTarget() {
    spawnTarget(randomValidSpawnPos());
}

//Spawn target at a indicated position
//pre: None
//Post: None
void Board::spawnTarget(Vec2D pos) {
    Target t = Target();
    Entity *newTarget = spawnEntityCopyAt(pos, &t);
    targets.push(newTarget);
}

void Board::runActors() {
    for(int i=0; i<actors.getSize(); i++) {
        actors.get(i)->runState();
    }
}