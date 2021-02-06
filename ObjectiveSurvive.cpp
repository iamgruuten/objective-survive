//Team members - Lee Quan Sheng and Eugene Long
//Group 8

//#include "Game.h"
#include "Board.h"
#include "Vec2D.h"
#include "VArray.cpp"
#include "EntityClasses.h"
#include <iostream>
#include "CSVParser.h"

int main() {
    
    

    Board b = *CSVParser::parseMapFile("b.csv");
    Entity* e = b.getEntityAt(Vec2D(1,4));
    b.display();

    e->runState();

    //Game game = Game();
    //game.start();
    return 0;
}