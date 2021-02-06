//Team members - Lee Quan Sheng and Eugene Long
//Group 8

//#include "Game.h"
#include "Board.h"
#include "Vec2D.h"
#include "VArray.cpp"
#include <iostream>

int main() {
    
    Board b = Board(12, 1);
    b.display();
    std::cout << b.neighboursForSpaceAt(Vec2D(0,1)).getSize() << std::endl;
    //Game game = Game();
    //game.start();
    return 0;
}