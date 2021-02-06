#include "EffectClasses.h"
#include "Board.h"
#include "Entity.h"
#include "algoMethods.h"
#include <math.h>

// DamageMoveEffect implementation

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