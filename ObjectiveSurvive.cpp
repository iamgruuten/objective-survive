//Team members - Lee Quan Sheng and Eugene Long
//Group 8

//#include "Game.h"
#include "Board.h"
#include "Vec2D.h"
#include "VArray.cpp"
#include "EntityClasses.h"
#include <iostream>

int main() {
    
    Board b = Board(12, 12);
    b.display();
    
    Melee* m = new Melee();
    b.spawnEntityCopyAt(Vec2D(3, 3), m);
    m->runState();

    //Game game = Game();
    //game.start();
    return 0;
}