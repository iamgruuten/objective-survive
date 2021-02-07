//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#include "Entity.h"
#include "Vec2D.h"
#include "Spell.h"
#include "Board.h"
#include "VArray.cpp"

//Initialize Entity
//pre: None
//Post: Sets the attributes of the entities
Entity::Entity(int hp, int armor, int maxmp, bool moveable, bool actor, bool pathable) : hp(hp), armor(armor), maxMovePoints(maxmp), movePoints(maxmp), pos(Vec2D(0, 0)), boardRef(nullptr), isActor(actor), isMoveable(moveable), isPathable(pathable), isTarget(false), spells(nullptr) {

    spells = new VArray<Spell*>();
}

//Deconstructs the entity
//pre: None
//Post: None
Entity::~Entity() {
    delete spells;
}

//Sets Hp of the entity
//pre: None
//Post: The hp is set as its own default value 
void Entity::setHp(int val) {
    hp = val;
}


//Get Hp of the entity
//pre: None
//Post: None
int Entity::getHp() {
    return hp;
}


//Deducts Hp of the entity
//pre: None
//Post: The new hp is updated based on the damage received 
void Entity::deductHp(int val) {
    hp -= val;

    //CHECK DEATH
    if(hp <= 0) {
        kill();
    }
}


//Sets Armor of the entity
//pre: None
//Post: The armor is set as its own default value
void Entity::setArmor(int val) {
    armor = val;
}

//Gets Armor of the entity
//pre: The entity must exist in the board
//Post: None
int Entity::getArmor() {
    return armor;
}

//Get isAbleToMove of the entity 
//pre: The entity must exist in the board
//Post: None
bool Entity::canMove() {
    return isMoveable;
}

//Get isActor of the entity
//pre: The entity must exist in the board
//Post: None
bool Entity::canAct() {
    return isActor;
}

//Sets board to its entity
//pre: The entity must exist in the board
//Post: The board that is initialize is set to the entity
bool Entity::canBePathed() {
    return isPathable;
}

bool Entity::canBeTargeted() {
    return isTarget;
}

void Entity::setBoardRef(Board* b) {
    boardRef = b;
}


//Sets the position of the entity
//pre: The entity must exist in the board
//Post: The new position of the entity is updated 
void Entity::setPos(int px, int py) {
    pos.updatePosition(px, py);
}

//Gets POS of the entity
//pre: The entity must exist in the board
//Post: None
Vec2D Entity::getPos() {
    return pos;
}

//Add spells of the entity
//pre: None
//Post: The new spell is added to the entity
void Entity::addSpell(Spell* spell) {
    if(spells != nullptr) {
        spells->push(spell);
    }
}

//Remove Spell of the entity
//pre: None
//Post: The spell index is remove from the entity
void Entity::removeSpell(int index) {
    if(spells != nullptr) {
        spells->remove(index);
    }
}

//Execute Spell of the entity to location 
//pre: None
//Post: The spell is insert to the board space 
void Entity::executeSpell(int index, Board& board, Vec2D tgtPos, int rotations) {
    if(spells != nullptr) {
        Spell *spell = spells->get(index);
        spell->activateSpell(board, tgtPos, rotations);
    }
}

//Remove entity from board when HP hits 0
//pre: None
//Post: The entity is removed from the board
void Entity::kill() {
    boardRef->despawnEntityAt(pos);
}
