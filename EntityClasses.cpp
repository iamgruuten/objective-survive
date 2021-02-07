#include "EntityClasses.h"
#include "Entity.h"
#include "FSMStack.h"
#include "Board.h"
#include "BHPriorityQueue.h"
#include "Pathfinder.h"
#include "EffectClasses.h"
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

    VArray<Entity* > targets = boardRef->getTargets();
    BHPriorityQueue<Entity*> bhpq;

    for(int t = 0; t < targets.getSize(); t++)
    {
        Entity* e = targets.get(t);
        int distance = this->getPos().getL1DistanceTo(e->getPos());
        bhpq.insert(distance, e);
    }

    Entity* tgt = bhpq.extract();


    std::string stateDesc = fsmStack.popState();
    
    if(stateDesc == "search") {
        VArray<Vec2D> path = getPathToTarget(*boardRef, pos,tgt->getPos());

        std::cout << path.getSize() << std::endl;
        for(int i=0; i<path.getSize()-1; i++) {
            std::cout << (std::string) path.get(i) << std::endl;
            boardRef->recursiveMoveEntityAt(path.get(i), path.get(i+1), true);
            if(movePoints == 0){
                break;
            }
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



double heuristicCalculation(int a_x, int a_y, int b_x, int b_y, int a_health, int b_health){
    return sqrt((a_x- b_x)^2 + (a_y - b_y)^2 + (a_health - b_health)^2) ;
}


int Melee::getScoreForPosition(Vec2D pos) {
    // TODO: IMPLEMENT THIS
    // THE LOWER THE SCORE THE BETTER THE MOVE
    //Ranged
    VArray<Entity* > entities = boardRef->getTargets();

    //Check if i can attack the target within the position
    
    BHPriorityQueue<Entity*> bhpq; 
    double rewards = 0;

    for(int e = 0; e < entities.getSize(); e++)
    {
        Entity* a = entities.get(e);

        Vec2D vol = a->getPos() - this->pos;
        
        if((vol == Vec2D(-1, 0)) || (vol == Vec2D(0,-1)) || (vol == Vec2D(1,0)) || (vol == Vec2D(0,1))){
            return 100;
        }
    }

    return 0;
}

//Ranged
Ranged::Ranged(): Entity(3, 2, 1, true, true) {
    fsmStack.pushState("ranger");
}

Ranged::Ranged(int hp, int armor, int maxmp): Entity(hp, armor, maxmp, true, true) {
    fsmStack.pushState("ranger");
}

Ranged::~Ranged() {}

Entity* Ranged::clone(){
    Ranged *ranged = new Ranged();
    ranged->setHp(hp);
    ranged->setArmor(armor);
    return ranged;
}



void Ranged::runState(){
 

    //If closest opponent unit is less than 3 tiles away - Action: Move Away
    //If opponenet is more than 6 tiles away - Move towards closest unit

    boardRef->display();

}


void Ranged::display(){
    std::cout << "m";
}

int Ranged::getScoreForTileState(TileState tileState) {
    switch(tileState) {
        case normal:
            return 1;
        case water:
            return 2;
        case hole:
            return 999;
    }
}

int Ranged::getScoreForPosition(Vec2D pos) {
    // TODO: IMPLEMENT THIS
    // THE LOWER THE SCORE THE BETTER THE MOVE

    //Ranged
    VArray<Entity* > entities = boardRef->getTargets();

    //Check if i can attack the target within the position
    
    BHPriorityQueue<Entity*> bhpq; 
    double rewards = 0;

    for(int e = 0; e < entities.getSize(); e++)
    {
        Entity* a = entities.get(e);

        rewards = rewards + heuristicCalculation(pos.x, pos.y, a->getPos().x, a->getPos().y, a->getHp(), this->hp);
    }

    return rewards;
}

void Ranged::onDeath(){
    Board *board = boardRef;
    board->despawnEntityAt(pos);
}

Target::Target() : Entity(10, 0, 0, false, false) {}

Target::Target(int hp, int armor) : Entity(hp, armor, 0, false, false) {}

Target::~Target() {}

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