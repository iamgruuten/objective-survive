#include "EffectClasses.h"
#include "Board.h"
#include "Entity.h"
#include "algoMethods.h"

// DamageMoveEffect implementation

void DamageMoveEffect::applyEffect(Board& b, AbsolutePosition tgtPos, Directions newFacing) {
    // translate relative position to absolute position
    AbsolutePosition effectPos = relPos.getAbsolutePos(tgtPos);

    // update knockback direction in accordance to rotation
    Directions knockbackDir = facing;
    RotationHandler::maintainRelativeDirection(knockbackDir, up, newFacing);

    // GUARD affected entity is not null
    Entity* entityRef = b.getEntityAt(effectPos);
    if (entityRef == NULL) {
        return;
    }

    // Damage

    int eHP = entityRef->getHp();
    int eDef = entityRef->getArmor();
    entityRef->deductHp(max(0, eDef - damage));

    // Move

    // GUARD affected entity can be knocked back
    if (!entityRef->canMove()) {
        return;
    }

    AbsolutePosition kbPos = effectPos;
    AbsolutePosition chkPos = effectPos;

    // check collision
    Entity* collidedEntity = NULL;

    for(int m=0;m<tiles;m++) {
        chkPos.movePosition(knockbackDir);

        if(!b.checkPosWithinBoard(chkPos)) {
            //hit border
            break;
        }
        // else, position is valid for moving to
        
        Entity* collidedEntity = b.getEntityAt(chkPos);

        if(collidedEntity != NULL) {
            // collision occured
            entityRef->deductHp(1);
            collidedEntity->deductHp(1);
            break;
        }
        // else, no collision, position remains valid
        kbPos = chkPos;
    }

    // finally, move entity to result location
    b.moveEntity(effectPos, kbPos);
}