//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Game

// The Game object keeps track of the game's state
// and implements the main loop of the application.

#ifndef game_h
#define game_h
#include "FSMStack.h"
#include "Queue.h"
#include "Entity.h"
#include <string>

enum GameStates: int {
    quit = -1, mainMenu = 0, running = 1
};

class Game : protected Stateful {
private:
    Board* b;
public:
    Game();
    ~Game();

    void pushState(GameStates state);
    GameStates getState();
    void runState();

    void start();
    void runMenu();
    void initGame();
    void runGame();
    void runStep();
    void finishGame();
    void eventTick();
};

#endif