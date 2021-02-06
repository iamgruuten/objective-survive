#include "csvParser.h"
#include "VArray.h"
#include "Tile.h"
#include "Board.h"
#include "Entity.h"
#include "PositionClasses.h"

#include <fstream>
#include <string>
#include <iostream>

#include "Vec2D.h"

Board csvParser::LoadMap(std::string filePath){
    Board board = Board(12, 12);

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
            //X refers to the x axis pos
            //Y refers to the y axis pos
            Tile t;
            t.pushState(std::stoi(field))
            Vec2D pos = Vec2D(x, y);

            board.setTileAt(pos, t);
            
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
            
            //if inside the csv file is a 1, refers to spawn a mountain
            if(field == 1){
            Vec2D pos = Vec2D(x, y);
            Entity e = Walls().setUp();

                board.spawnEntityCopyAt(pos, e);
            }
            //else dont spawn anything
        }
        
    }

}