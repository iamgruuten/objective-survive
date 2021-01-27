#ifndef fsmstack_h
#define fsmstack_h
#include <string>

class State {
private:
    std::string description;
    State *bottom;
public:
    State() : description("\0"), bottom(NULL) {}
    State(std::string description) : description(description), bottom(NULL) {}
    void addToBottom(State* s);
    State* popFromBottom();
};

class FSMStack {
private:
    State *top;
    int size;

public:
    FSMStack() : top(NULL), size(0) {}
    ~FSMStack();
    std::string popState();
    std::string getTopState();
    void pushState(std::string description);
};

class Stateful {
protected:
    FSMStack fsmStack;
    FSMStack stash;

public:
    Stateful() : fsmStack(), stash() {}
    virtual ~Stateful();
    void stashState();
    void unstashState();
    virtual void runState() = 0;
};

#endif