#include "EntityClasses.h"
#include "FSMStack.h"
#include "Board.h"
#include "BHPriorityQueue.h"
#include <iostream>

Walls::Walls(): Entity(3, 0, 0, false) {
}

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

void Walls::onDeath(){}

//Melee
Melee::Melee(): Entity(3, 3, 2, true) {
    fsmStack.pushState("SpawnMelee");
}


Entity* Melee::clone(){
    Melee *melee = new Melee();
    melee->setHp(hp);
    melee->setArmor(armor);
    return melee;
}

void Melee::runState(){
    melee.setPos()
}

void Melee::display(){
    std::cout << "m";
}

void Melee::onDeath(){
    Board *board = boardRef;

    board->despawnEntityAt(pos);
}


//Ranged
Ranged::Ranged(): Entity(3, 2, 1, true) {
    fsmStack.pushState("SpawnRanged");
}

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
