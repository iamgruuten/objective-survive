#include "EntityClasses.h"
#include "Entity.h"
#include "FSMStack.h"
#include "Board.h"
#include "BHPriorityQueue.h"
#include "Pathfinder.h"
#include <iostream>

Walls::Walls(): Entity(3, 0, 0, false, false) {}

Walls::Walls(int hp, int armor): Entity(hp, armor, 0, false, false) {}

Walls::~Walls() {}

Entity* Walls::clone() {
    Walls *wall = new Walls();
    wall->setHp(hp);
    wall->setArmor(armor);
    return wall;
}

void Walls::runState(){}

void Walls::display(){
    std::cout << "A";
}

void Walls::onDeath(){
    boardRef->despawnEntityAt(pos);
}

//Melee
Melee::Melee(): Entity(3, 3, 2, true, true) {
    fsmStack.pushState("search");
}

Melee::Melee(int hp, int armor, int maxmp): Entity(hp, armor, maxmp, true, true) {
    fsmStack.pushState("search");
}

Melee::~Melee() {}

Entity* Melee::clone(){
    Melee *melee = new Melee();
    melee->setHp(hp);
    melee->setArmor(armor);
    return melee;
}

void Melee::runState(){
    std::string stateDesc = fsmStack.popState();
    if(stateDesc == "search") {
        VArray<Vec2D> path = getPathToTarget(*boardRef, pos, Vec2D(6,13));
        std::cout << path.getSize() << std::endl;
        for(int i=0; i<path.getSize()-1; i++) {
            std::cout << (std::string) path.get(i) << std::endl;
            boardRef->recursiveMoveEntityAt(path.get(i), path.get(i+1), true);
        }
    }
    boardRef->display();
}

void Melee::display(){
    std::cout << "m";
}

void Melee::onDeath(){
    boardRef->despawnEntityAt(pos);
}

int Melee::getScoreForTileState(TileState tileState) {
    switch(tileState) {
        case normal:
            return 1;
        case water:
            return 2;
        case hole:
            return 999;
    }
}

//Ranged
Ranged::Ranged(): Entity(3, 2, 1, true, true) {
    fsmStack.pushState("SpawnRanged");
}

Ranged::Ranged(int hp, int armor, int maxmp): Entity(hp, armor, maxmp, true, true) {
}

Ranged::~Ranged() {}

Entity* Ranged::clone(){
    Ranged *ranged = new Ranged();
    ranged->setHp(hp);
    ranged->setArmor(armor);
    return ranged;
}

void Ranged::runState(){
    //Ranged

    //Heuristic Function


}

double heuristicCalculation(int a_x, int a_y, int b_x, int b_y, int a_health, int b_health){
    return sqrt((a_x- b_x)^2 + (a_y - b_y)^2 + (a_health - b_health)^2) ;
}

void Ranged::display(){
    std::cout << "m";
}

void Ranged::onDeath(){
    Board *board = boardRef;
    board->despawnEntityAt(pos);
}

Target::Target() : Entity(10, 0, 0, false, false) {}

Target::Target(int hp, int armor) : Entity(hp, armor, 0, false, false) {}

Entity* Target::clone() {
    return new Target(hp, armor);
}

void Target::runState() {}

void Target::display() {
    std::cout << "!";
}

void Target::onDeath() {
    boardRef->despawnEntityAt(pos);
}