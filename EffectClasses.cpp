//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

#include "EffectClasses.h"
#include "Board.h"
#include "Entity.h"
#include "algoMethods.h"
#include "Vec2D.h"
#include <math.h>
#include <iostream>

// Effect implementation
Effect::~Effect() {}

// DamageMoveEffect implementation

DamageMoveEffect::~DamageMoveEffect() {}

//Give damage to entity (units)
//pre: None
//Post: Entity (Units) that is being attacked attributes will be updated accordingly
void DamageMoveEffect::applyEffect(Board& b, Vec2D tgtPos, int rotations) {
    Vec2D instanceRelPos = relPos;

    // apply rotations to effect relpos
    instanceRelPos.transformRotations(rotations);

    // Get effect position by applying this attack's relPos to tgtPos
    Vec2D effectPos = instanceRelPos + tgtPos;

    // GUARD entity exists at tgt
    Entity *tgt = b.getEntityAt(effectPos);
    if(tgt == nullptr) {
        return;
    }

    // Damage tgt entity
    int effectiveDamage = max(0, damage - tgt->getArmor());
    tgt->deductHp(effectiveDamage);

    // check if entity is still alive for move
    tgt = b.getEntityAt(effectPos);
    if(tgt == nullptr) {
        return;
    }

    // Move tgt entity

    // GUARD tgt entity can be moved before starting
    if(!tgt->canMove()) {
        return;
    }

    // transform knockback vector to match rotations
    Vec2D instanceKBRelPos = knockbackVec;
    instanceKBRelPos.transformRotations(rotations);
    Vec2D resultPos = instanceKBRelPos + effectPos;

    // use recursive move that has checks for collision to calculate knockback
    b.recursiveMoveEntityAt(effectPos, resultPos, true);
}