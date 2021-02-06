#include "Board.h"
#include "Vec2D.h"

Board::Board(int w, int h) {
    width = w;
    height = h;

    spaces = new VArray< VArray< Space* >* >(0, h);
    for(int i=0; i<h; i++) {
        spaces->push(new VArray< Space* >(0, w));
        for(int j=0; j<w; j++) {
            spaces->get(i)->push(new Space);
        }
    }
}

Board::~Board() {
    // Deconstructor
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            delete spaces->get(i)->get(j);
        }
        delete spaces->get(i);
    }
    delete spaces;
}

Entity* Board::getEntityAt(Vec2D pos) {
    // GUARD pos is within board
    if(!posIsWithinBoard(pos)) {
        return NULL;
    }

    return spaces->get(pos.y)->get(pos.x)->entity;
}

void moveEntityAt(Vec2D origin, Vec2D tgt) {

}