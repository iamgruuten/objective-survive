#include "EntityClasses.h"
#include "Entity.h"
#include "FSMStack.h"
#include "Board.h"
#include "BHPriorityQueue.cpp"
#include "Pathfinder.h"
#include "EffectClasses.h"
#include "Vec2D.h"
#include "Spell.h"
#include <iostream>

Walls::Walls(): Entity(3, 0, 0, false, false, false) {}

Walls::Walls(int hp, int armor): Entity(hp, armor, 0, false, false, false) {}

Walls::~Walls() {}

Entity* Walls::clone() {
    Walls *wall = new Walls();
    wall->setHp(hp);
    wall->setArmor(armor);
    return wall;
}

void Walls::runState(){}

void Walls::display(){
    std::cout << "A";
}

Spell* MeleeSpells() {
    Spell *spell = new Spell();
    DamageMoveEffect *effect = new DamageMoveEffect(0, 0, 2, Vec2D(0, 2));
    spell->addEffect(effect);
    return spell;
}

//Melee
Melee::Melee(): Entity(3, 3, 2, true, true, true) {
    fsmStack.pushState("attackClosest");
    addSpell(MeleeSpells());
}

Melee::Melee(int hp, int armor, int maxmp): Entity(hp, armor, maxmp, true, true, true) {
    fsmStack.pushState("attackClosest");
    addSpell(MeleeSpells());
}

Melee::~Melee() {}

Entity* Melee::clone(){
    Melee *melee = new Melee(hp, armor, maxMovePoints);
    return melee;
}

void Melee::runState(){
    std::string stateDesc = fsmStack.popState();

    if(stateDesc == "attackClosest") {

        // Get closest target
        VArray<Entity* > targets = boardRef->getTargets();

        // GUARD targets exist
        if(targets.getSize() == 0) {
            // preserve state
            fsmStack.pushState("attackClosest");
            std::cout << "No targets remain!" << std::endl;
            return;
        }

        BHPriorityQueue<Entity*> bhpq;

        for(int t = 0; t < targets.getSize(); t++)
        {
            Entity* e = targets.get(t);
            int distance = this->getPos().getL1DistanceTo(e->getPos());
            bhpq.insert(distance, e);
        }

        // target at top of priority queue has lowest L1 dist
        Entity* tgt = bhpq.extract();

        // Path to target and move as far as possible
        Vec2D tgtPos = tgt->getPos();
        VArray<Vec2D> path = getPathToTarget(boardRef, pos, tgtPos);

        if(path.getSize() > 0) {
            // -2 to exclude last tile (actual tgt position)
            for(int i=0; i<path.getSize()-2; i++) {

                //check movement cost for next tile
                int moveCost = boardRef->getTileAt(path.get(i+1))->movementCostForTile();
                if(movePoints - moveCost < 0) {
                    break; // stop moving if movecost is too high
                } else {
                    movePoints -= moveCost;
                    std::cout << (std::string) path.get(i) << std::endl;
                boardRef->recursiveMoveEntityAt(path.get(i), path.get(i+1), true);
                }

            }
            std::cout << "moved to " << (std::string) getPos() << std::endl;
            movePoints = maxMovePoints;
        } else {
            std::cout << "Did not move!" << std::endl;
        }

        // attempt to attack target

        // check if target is within attack distance while obtaining rotations
        Vec2D checkRelPos = Vec2D(0, 1);
        for(int rot=0; rot<4; rot++) {
            if(checkRelPos + pos == tgtPos) {
                // found target, attack
                std::cout << "attacked enemy" << std::endl;
                executeSpell(0, *boardRef, tgtPos, rot);
            }
            // else, rotate and check next direction
            checkRelPos.transformCW90();
        }
        // else, target not found, continue
        
        // preserve state
        fsmStack.pushState("attackClosest");
    }
}

void Melee::display(){
    std::cout << "m";
}

int Melee::getScoreForTileState(TileState tileState) {
    switch(tileState) {
        case normal:
            return 1;
        case water:
            return 2;
        case hole:
            return 999;
    }
}

int Melee::getScoreForPosition(Vec2D pos) {
    // Heuristic is unused.
    return 0;
}

//Ranged
Ranged::Ranged(): Entity(3, 2, 1, true, true, true) {
    fsmStack.pushState("attackAtRange");
}

Ranged::Ranged(int hp, int armor, int maxmp): Entity(hp, armor, maxmp, true, true, true) {
    fsmStack.pushState("attackAtRange");
}

Ranged::~Ranged() {}

Entity* Ranged::clone(){
    Ranged *ranged = new Ranged();
    ranged->setHp(hp);
    ranged->setArmor(armor);
    return ranged;
}

void Ranged::runState(){
    std::string stateDesc = fsmStack.popState();

    if(stateDesc == "attackAtRange") {
        //If closest opponent unit is less than 3 tiles away - Action: Move Away
        //If opponenet is more than 6 tiles away - Move towards closest unit

        VArray<Entity* > targets = boardRef->getTargets();
        BHPriorityQueue<Entity*> bhpq;

        for(int t = 0; t < targets.getSize(); t++)
        {
            Entity* e = targets.get(t);
            int distance = this->getPos().getL1DistanceTo(e->getPos());
            bhpq.insert(distance, e);
        }

        Entity* tgt = bhpq.extract();

        std::string stateDesc = fsmStack.popState();
        
        Vec2D nextPos = bestMoveForUnit(*boardRef, movePoints, tgt->getPos());

        if(stateDesc == "search") {
            VArray<Vec2D> path = getPathToTarget(boardRef, pos, nextPos);
            std::cout << path.getSize() << std::endl;
            for(int i=0; i<path.getSize()-1; i++) {
                std::cout << (std::string) path.get(i) << std::endl;
                boardRef->recursiveMoveEntityAt(path.get(i), path.get(i+1), true);
                if(movePoints == 0){
                    break;
                }
            }
        }

         // preserve state
        fsmStack.pushState("attackAtRange");
    }
}

void Ranged::display(){
    std::cout << "r";
}

int Ranged::getScoreForTileState(TileState tileState) {
    switch(tileState) {
        case normal:
            return 1;
        case water:
            return 2;
        case hole:
            return 999;
    }
}

double heuristicCalculation(int a_x, int a_y, int b_x, int b_y, int a_health, int b_health){
    return sqrt((a_x- b_x)^2 + (a_y - b_y)^2 + (a_health - b_health)^2) ;
}

int Ranged::getScoreForPosition(Vec2D pos) {
    // TODO: IMPLEMENT THIS
    // THE LOWER THE SCORE THE BETTER THE MOVE

    //Ranged
    VArray<Entity* > entities = boardRef->getTargets();

    //Check if i can attack the target within the position
    
    BHPriorityQueue<Entity*> bhpq; 
    double rewards = 0;

    for(int e = 0; e < entities.getSize(); e++)
    {
        Entity* a = entities.get(e);

        rewards = rewards + heuristicCalculation(pos.x, pos.y, a->getPos().x, a->getPos().y, a->getHp(), this->hp);
    }

    return rewards;
}

Target::Target() : Entity(5, 0, 0, true, false, true) {
    isTarget = true;
}

Target::Target(int hp, int armor) : Entity(hp, armor, 0, true, false, true) {
    isTarget = true;
}

Target::~Target() {}

Entity* Target::clone() {
    return new Target(hp, armor);
}

void Target::runState() {}

void Target::display() {
    std::cout << "!";
}