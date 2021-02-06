#include "CSVParser.h"
#include "VArray.cpp"
#include "Tile.h"
#include <string>

#include <iostream>
#include <fstream>

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

Board* CSVParser::parseMapFile(std::string filename) {
    
    std::string rawMap = getTextFromFile(filename);
    rawMap.pop_back(); // remove EOF newline

    VArray<VArray<TileState>* > temp;
    temp.push(new VArray<TileState>());

    int row = 0;
    for(int i=0; i<rawMap.length(); i++) {
        switch(rawMap[i]) {
            case ',': break;
            case '\n':
                row ++;
                temp.push(new VArray<TileState>());
                break;
            case '0':
                temp.get(row)->push(normal);
                break;
            case '1':
                temp.get(row)->push(water);
                break;
            case '2':
                temp.get(row)->push(hole);
                break;
        }
    }

    int height = temp.getSize();
    int width = temp.get(0)->getSize();

    Board* board = new Board(width, height);

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            TileState state = temp.get(i)->get(j);
            board->setTileStateAt(Vec2D(j, i), state);
        }
    }

    return board;
}