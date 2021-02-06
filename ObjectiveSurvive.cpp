//Team members - Lee Quan Sheng and Eugene Long
//Group 8

//#include "Game.h"
#include "Board.h"
#include "Vec2D.h"
#include "VArray.cpp"
#include "EntityClasses.h"
#include <iostream>
#include "CSVParser.h"
#include "FSMStack.h"

int main() {
    
    

    Board b = *CSVParser::parseMapFile("b.csv");
<<<<<<< HEAD
    //Melee* m = new Melee();
    //b.spawnEntityCopyAt(Vec2D(4, 4), m);
    b.display(); 
=======
    Entity* e = b.getEntityAt(Vec2D(1,4));
    b.display();
>>>>>>> 47bf49a0662c3c0617f65a5bd2b457fb4a18c16e

    e->runState();

    //Game game = Game();
    //game.start();
    return 0;
}