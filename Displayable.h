//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// This is a component class that ensures its inheritors
// implement a display function.

#ifndef displayable_h
#define displayable_h

class Displayable {
private:
public:
    virtual void display() = 0;
};

#endif