#include "Board.h"
#include "Board.cpp"

int main() {
    Board b = Board(13);
    b.enableOverlay();
    b.display();
    return 0;
}