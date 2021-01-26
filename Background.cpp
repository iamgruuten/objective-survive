#include "Background.h"
#include <string>

Background::Background() {
    setIcon(' ');
}

Background::Background(Backgrounds bg) {
    switch(bg) {
        case none: // none
            setIcon(' ');
            break;
        case plain: // plain
            setIcon('.');
            break;
        default:
            setIcon(' ');
    }
}

Background::~Background() {}

void Background::applyEffects() {}