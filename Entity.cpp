#include "Entity.h"
#include "PositionClasses.h"
#include "Spell.h"
#include "Board.h"
#include "VArray.cpp"

Entity::Entity(char icon, int hp, int armor, int maxmp, int posx, int posy, bool moveable) : pos(AbsolutePosition(posx, posy)), boardRef(NULL) {
    setIcon(icon);
    hp = hp;
    armor = armor;
    maxMovePoints = maxmp;
    movePoints = maxmp;
    isMoveable = moveable;
}

Entity::~Entity() {

}

void Entity::setHp(int val) {
    hp = val;
}

int Entity::getHp() {
    return hp;
}

void Entity::deductHp(int val) {
    hp -= val;

    //CHECK DEATH
    onDeath();
}

void Entity::setArmor(int val) {
    armor = val;
}

int Entity::getArmor() {
    return armor;
}

bool Entity::canMove() {
    return isMoveable;
}

void Entity::setBoardRef(Board* b) {
    boardRef = b;
}

void Entity::setPos(int px, int py) {
    pos.updatePosition(px, py);
}

AbsolutePosition Entity::getPos() {
    return pos;
}

void Entity::addSpell(Spell spell) {
    spells.push(spell);
}

void Entity::removeSpell(int index) {
    spells.remove(index);
}

void Entity::executeSpell(int index, Board& board, int dist, Directions facing) {
    Spell spell = spells[index];
    spell.activateSpell(board, dist, facing, pos);
}