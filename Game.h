//Team members - Lee Quan Sheng and Eugene Long
//Group 8

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
    Queue<Entity*>* turnQueue;
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
    void finishGame();
    void eventTick();
};

#endif