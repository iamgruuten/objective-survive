#include "EntityClasses.h"

Walls::Walls(): Entity(3, 0, 0, false) {


}

Melee::Melee(int hp, int armor, int maxmp, int x, int y, bool moveable): Entity(hp, armor, maxmp, x, y, moveable) {
}

Ranged::Ranged(int hp, int armor, int maxmp, int x, int y, bool moveable): Entity(hp, armor, maxmp, x, y, moveable) {
}