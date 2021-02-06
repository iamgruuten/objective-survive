#include "EntityClasses.h"
#include "FSMStack.h"
#include "Board.h"
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

}

void Ranged::display(){
    std::cout << "m";
}

void Ranged::onDeath(){
    Board *board = boardRef;
    board->despawnEntityAt(pos);
}
