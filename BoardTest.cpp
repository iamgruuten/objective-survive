#include "Board.h"

int main() {
    Board b = Board(13);
    b.enableOverlay();
    b.display();
    return 0;
}