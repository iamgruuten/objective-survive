//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// CSVParser

// This helper class is a wrapper for the methods that
// help instantiate a Board object from a csv file

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