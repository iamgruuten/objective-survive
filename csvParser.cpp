#include "csvParser.h"
#include "VArray.h"
#include "Tile.h"
#include "Board.h"
#include "Entity.h"
#include "PositionClasses.h"

#include <fstream>
#include <string>
#include <iostream>


Board csvParser::LoadMap(std::string filePath){
    Board board = new Board();

    std::ifstream boardMap(filePath);
   std::string line;
    int y = 0;
    int x = 0;

    while(std::getline(boardMap, line, '\n')){
        y = y + 1;
        std::istringstream s(line);
        std::string field;

        while (getline(s, field,',')){
            x = x + 1;
            
        }
        
    }

    return board;
}

}

csvParser::LoadEntities(std::string filePath, Board* board){
    std::ifstream boardMap(filePath);
    VArray<Entity> map = VArray<Entity>();

    std::string line;
    int y = 0;
    int x = 0;

    while(std::getline(boardMap, line, '\n')){
        y = y + 1;
        std::istringstream s(line);
        std::string field;

        while (getline(s, field,',')){
            x = x + 1;
            AbsolutePosition pivot = AbsolutePosition(x,y);
            
        }
        
    }

}