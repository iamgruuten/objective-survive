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
}

std::string FSMStack::popState(){
    if(size != 0){
        State* tempState = top;
    }

}

std::string FSMStack::getTopState(){

}

void FSMStack::pushState(std::string description){

}

// Stateful implementation

Stateful::~Stateful() {


}