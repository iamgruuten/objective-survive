#include "Displayable.h"
#include <iostream>

void Displayable::setIcon(char i) {
    icon = i;
}

void Displayable::display() {
    std::cout << icon;
}