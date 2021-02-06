#ifndef csvparser_h
#define csvparser_h

#include "Board.h"
#include "Tile.h"
#include "VArray.h"

#include <string>

class CSVParser {
private:
    static std::string getTextFromFile(std::string filename);
public:
    static Board* parseMapFile(std::string filename);
};

#endif