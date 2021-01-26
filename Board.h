#ifndef board_h
#define board_h
#include "VArray.h"
#include "Entity.h"
#include "Background.h"
#include "Displayable.h"
#include "Position.h"

struct Tile {
private:
    char overlay;
    Entity* foreground;
    Background background;
public:
    Tile();
    ~Tile();
    Entity* getForeground();
    Background& getBackground();
    void setOverlay(char icon);
    void clearOverlay();
    void enteredForeground(Entity* entity);
    void leftForeground();
    void setBackground(Background bg);
    void display();
    void displayOverlay();
};

class Board {
private:
    VArray< VArray<Tile> > grid;
    bool showOverlay;
public:
    Board(int size);
    ~Board();
    Entity* getEntityAt(Position pos);
    Background& getBackgroundAt(Position pos);
    void enableOverlay();
    void disableOverlay();
    void resetOverlay();
    void display();
};

#endif