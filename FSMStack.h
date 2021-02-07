//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// FSMStack

// The FSMStack is a Stack data structure used
// to implement Finite-State-Machines.

// These Finite State Machines are used in the
// Entity classes and the Game instance to 
// run specific actions based on the current
// state of the object instance.

// The Stateful Class is a component class that
// other classes can inherit to utilise a 
// Finite-State-Machine.

#ifndef fsmstack_h
#define fsmstack_h
#include <string>

//State is an implementation to keep track of the state of an object
class State {

private:
    std::string description;
    State *bottom;

public:
    //State is intialize 
    //pre: None
    //Post: None
    State() : description("\0"), bottom(NULL) {}

    State(std::string description) : description(description), bottom(NULL) {}
    
    //Stack the state above its next state of the entity
    //pre: The state must exist in the stack
    //Post: None
    void setBottom(State *state);

     //Gets the bottom state of the state stack
    //pre: The state must exist in the stack
    //Post: None
    State* getBottom();

    //Gets the description state
    //pre: The state must exist in the stack
    //Post: None
    std::string getDescription();

};

//Stack 
class FSMStack {
private:
    State *top;
    int size;

public:
    FSMStack() : top(NULL), size(0) {}
    ~FSMStack();

    //Remove the state from the stack
    //pre: The state must exist in the stack
    //Post: None
    std::string popState();
    
    //Gets the top state from the stack
    //pre: None
    //Post: None
    std::string getTopState();

    //Insert state on top of the stack
    //pre: None
    //Post: The new state is insert on the top of the stack
    void pushState(std::string description);
};

//Stateful
class Stateful {
protected:
    FSMStack fsmStack;
    FSMStack stash;

public:
    Stateful() : fsmStack(), stash() {}
    virtual ~Stateful();

    //Stashing of the state
    //pre: None
    //Post: The state is retrieve and remove from the fsm stack and insert into the stash 
    void stashState();

    //Unstash of the state
    //pre: None
    //Post: The state is retrieve and remove from the stash and insert into the fsm stack
    void unstashState();

    //When the state become run, it is overriden by different objects
    //pre: None
    //Post: None
    virtual void runState() = 0;
};

#endif