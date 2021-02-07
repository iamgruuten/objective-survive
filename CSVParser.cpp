#include "CSVParser.h"
#include "VArray.cpp"
#include "Tile.h"
#include "Entity.h"
#include "EntityClasses.h"
#include <string>

#include <iostream>
#include <fstream>

//Retrieve Text from csv file
//pre: None
//Post: None
std::string CSVParser::getTextFromFile(std::string filename) {
    std::ifstream file(filename);

    std::string rawMap;
    std::string textStream;
    while(std::getline(file, textStream, '\n')) {
        rawMap = textStream + "\n" + rawMap;
    }

    file.close();

    return rawMap;
}

//Parse into a Full Map (Board) from the file 
//pre: None
//Post: Returns a full loaded board
Board* CSVParser::parseMapFile(std::string filename) {
    
    std::string rawMap = getTextFromFile(filename);
    rawMap.pop_back(); // remove EOF newline

    VArray<VArray<TileState>* > states;
    VArray<VArray<char>* > entities;
    states.push(new VArray<TileState>());
    entities.push(new VArray<char>());

    int row = 0;
    for(int i=0; i<rawMap.length(); i++) {
        switch(rawMap[i]) {
            case ',': break;
            case '\n':
                row ++;
                states.push(new VArray<TileState>());
                entities.push(new VArray<char>());
                break;
            case '0':
                states.get(row)->push(normal);
                entities.get(row)->push('\0');
                break;
            case '1':
                states.get(row)->push(water);
                entities.get(row)->push('\0');
                break;
            case '2':
                states.get(row)->push(hole);
                entities.get(row)->push('\0');
                break;
            case 'w':
            case 'm':
            case 'r':
                entities.get(row)->push(rawMap[i]);
                states.get(row)->push(normal);
        }
    }

    int height = states.getSize();
    int width = states.get(0)->getSize();

    Board* board = new Board(width, height);

    // Entity 'brushes'
    Walls wall = Walls();
    Melee melee = Melee();
    Ranged ranged = Ranged();

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            Vec2D pos = Vec2D(j, i);
            board->setTileStateAt(pos, states.get(i)->get(j));

            char entityType = entities.get(i)->get(j);
            if(entityType != '\0') {
                switch(entityType) {
                    case 'w':
                        board->spawnEntityCopyAt(pos, &wall);
                        break;
                    case 'm':
                        board->spawnEntityCopyAt(pos, &melee);
                        break;
                    case 'r':
                        board->spawnEntityCopyAt(pos, &ranged);
                        break;
                }
            }
        }
    }

    return board;
}