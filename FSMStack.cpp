//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

#include "FSMStack.h"
#include <string>


// State implementation

void State::setBottom(State *state){
    bottom = state;
}

State* State::getBottom(){
    return bottom;
}

std::string State::getDescription(){
    return description;
}

// FSMStack implementation

FSMStack::~FSMStack() {
    //Deconstructor
    while(size > 0) {
        popState();
    }
}

std::string FSMStack::popState(){
    std::string description = "";

    if(size > 0){
        State* tempState = top;
        top = top->getBottom();

        description = tempState->getDescription();
        delete tempState;
        size --;
    }

    return description;
}

std::string FSMStack::getTopState(){
    return top->getDescription();
}

void FSMStack::pushState(std::string description){
    State* state = new State(description);
    state->setBottom(top);
    top = state;
    size ++;
}

// Stateful implementation

Stateful::~Stateful() {}

void Stateful::stashState(){
    std::string description = fsmStack.popState();
    stash.pushState(description);
}

void Stateful::unstashState(){
    std::string description = stash.popState();
    fsmStack.pushState(description);
}