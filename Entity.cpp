//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Entity.h"
#include "Vec2D.h"
#include "Spell.h"
#include "Board.h"
#include "VArray.cpp"

Entity::Entity(int hp, int armor, int maxmp, bool moveable, bool actor) : pos(Vec2D(0, 0)), boardRef(NULL), isActor(actor) {
    hp = hp;
    armor = armor;
    maxMovePoints = maxmp;
    movePoints = maxmp;
    isMoveable = moveable;

    spells = new VArray<Spell>();
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
    if(hp < 0) {
        kill();
    }
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

bool Entity::canAct() {
    return isActor;
}

void Entity::setBoardRef(Board* b) {
    boardRef = b;
}

void Entity::setPos(int px, int py) {
    pos.updatePosition(px, py);
}

Vec2D Entity::getPos() {
    return pos;
}

void Entity::addSpell(Spell spell) {
    spells->push(spell);
}

void Entity::removeSpell(int index) {
    spells->remove(index);
}

void Entity::executeSpell(int index, Board& board, Vec2D tgtPos, int rotations) {
    Spell spell = spells->get(index);
    spell.activateSpell(board, tgtPos, rotations);
}

void Entity::kill() {
    boardRef->despawnEntityAt(pos);
    onDeath();
}
