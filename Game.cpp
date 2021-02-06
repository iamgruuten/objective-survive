#include "Game.h"
#include "FSMStack.h"
#include "VArray.cpp"
#include "Tile.h"
#include "csvParser.h"

#include <fstream>
#include <string>
#include <iostream>

Game::Game() : Stateful() {
    pushState(mainMenu);
}

Game::~Game() {}

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
            runGame();
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

void Game::runGame() {

    
    //TODO: Spawn board and set tile states
    //TODO: Spawn entities using .copy()
    //TODO: Add impt entities to entity turn array
    //TODO: Initialise event priority queue
    //TODO: Run event queue until break event occurs
    //TODO: Show end score
    //TODO: end and return to title
}

void Game::start() {
    runState();
}