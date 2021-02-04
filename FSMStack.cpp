#include "FSMStack.h"
#include <string>


// State implementation
State::~State(){
    //Deconstructor
    State* temp = bottom;

    while(temp != NULL){
        bottom = bottom->bottom;
        delete bottom;
        temp = bottom;
    }
    
}



void State::addToBottom(std::string s){
    State* state = new State;
    state->description = s;

    if(bottom != NULL){
        State* tempState = bottom;
        state->bottom = tempState;
    }

    bottom = state;
}

std::string State::getDescription(){
    return description;
}

State* State::popFromBottom(){
    if(bottom != NULL){
        State* tempState = bottom;

        if(bottom->bottom != NULL){
            bottom = bottom->bottom;

            tempState->description = "";
        }

        delete tempState;
    }

}

State* State::getBottom(){
    return bottom;
}



// FSMStack implementation

FSMStack::~FSMStack() {
    //Deconstructor
    State* temp = top;

    while(temp != NULL){
        top = top->getBottom();
        delete top;
        temp = top;
    }
}

std::string FSMStack::popState(){
    if(size != 0){
        State* tempState = top;
        delete tempState;
    }

        if(size != 0){
        State* tempState = top;

        if(top->getBottom() != NULL){
            top = top->getBottom();

            tempState->popFromBottom();
        }

        delete tempState;
    }

}

std::string FSMStack::getTopState(){
    return top->getDescription();
}

void FSMStack::pushState(std::string description){
    State* state = new State;
    state->addToBottom(description);

    if(top != NULL){
        State* tempState = top;
        state = tempState->getBottom();
        top = state;
    }else{
         State* tempState = state->getBottom();
         tempState = NULL;
         top = tempState;
    }
}

// Stateful implementation

Stateful::~Stateful() {
    //Deconstructor
}

void Stateful::stashState(){
    std::string description = fsmStack.popState();
    stash.pushState(description);
}

void Stateful::unstashState(){
    std::string description = stash.popState();
    fsmStack.pushState(description);
}