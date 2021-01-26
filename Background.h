#ifndef background_h
#define background_h
#include "Displayable.h"
#include <string>

enum Backgrounds {
    none = 0, plain = 1
};

class Background : public Displayable {
private:
    int effects;
public:
    Background();
    Background(Backgrounds bg);
    ~Background();
    void applyEffects();
};

#endif