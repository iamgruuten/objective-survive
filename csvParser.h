#include <iostream>
#include <string>
#include "Board.h"

//forward declaration
class AbsolutePosition;
class Board;

class csvParser{
    public:
        Board LoadMap(std::string);
        Board LoadEntities(std::string, Board board);

}