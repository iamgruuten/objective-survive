//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Game.h"
#include "FSMStack.h"
#include "VArray.cpp"
#include "Tile.h"
#include "EntityClasses.h"
#include "Vec2D.h"
#include "CSVParser.h"
#include "Queue.cpp"

#include <string>
#include <iostream>

Game::Game() : Stateful() {
    b = nullptr;
    pushState(mainMenu);
    turnQueue = new Queue<Entity*>();
}

Game::~Game() {
    if(turnQueue != nullptr) {
        delete turnQueue;
    }
}

void Game::pushState(GameStates state) {
    switch(state) {
        case mainMenu:
            fsmStack.pushState("mainmenu");
            break;
        case running:
            fsmStack.pushState("running");
            break;
        case quit:
            fsmStack.pushState("quit");
            break;
    }
}

GameStates Game::getState() {
    std::string state = fsmStack.popState();
    if(state == "mainmenu") { return mainMenu; }
    else if(state == "running") { return running; }
    else { return quit; }
}

void Game::runState() {
    switch(getState()) {
        case mainMenu:
            runMenu();
            runState();
            break;
        case running:
            initGame();
            // return to main menu after game ends
            pushState(mainMenu);
            runState();
            break;
        case quit:
            // stops recursively running current State
            break;
    }
}

void displayMenu() {
    std::cout << "\n\n\nObjective Survive" << std::endl;
    std::cout << "[1] Start Game" << std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cout << "> ";
}

void Game::runMenu() {
    int option;
    while(true) {
        displayMenu();
        std::cin >> option;

        if(option == 1) {
            pushState(running);
            break;
        } else if (option == 0) {
            pushState(quit);
            break;
        } else {
            std::cout << "Invalid option!\n" << std::endl;
            pushState(mainMenu);
        }
    }
}

void Game::initGame() {
    std::string filename;
    std::cout << "Enter filename of map to load: ";
    std::cin >> filename;

    b = CSVParser::parseMapFile(filename);
    VArray<Entity*> actors = b->getActors();

    for(int i=0; i<actors.getSize(); i++) {
        turnQueue->enqueue(actors.get(i));
    }

    runGame();
}

void Game::finishGame() {

    // reset turn queue
    while(!turnQueue->isEmpty()) {
        turnQueue->dequeue();
    }

}

void Game::runGame() {
    // main application loop
    while(true) {
        b->display();
        //TODO: Print menu bar and show available actions
        std::cout << "Simulation Controls" << std::endl;
        std::cout << "[1] Simulation Step" << std::endl;
        std::cout << "[2] Run Until Targets Destroyed" << std::endl;
        std::cout << "[9] Spawn New Target" << std::endl;
        std::cout << "[0] End Simulation" << std::endl;
        std::cout << "> ";

        int uin;
        std::cin >> uin;
    }
    
    finishGame();
}

void Game::start() {
    runState();
}