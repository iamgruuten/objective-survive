#include "Spell.h"
#include "Vec2D.h"
#include "EffectClasses.h"
#include "VArray.cpp"

Spell::Spell() {
    range = 0;
}

void Spell::addEffect(Effect* effect) {
    effects.push(effect);
}

void Spell::activateSpell(Board& board, int distance, Directions facing, Vec2D origin) {
    Vec2D relPos = Vec2D(0, distance);
    Vec2D pivot = Vec2D(0,0);
    RotationHandler::rotateToFace(relPos, &pivot, up, facing);
    Vec2D tgtPos = relPos.getL1DistanceTo(origin);

    for(int i=0; i<effects.getSize(); i++) {
        effects.get(i)->applyEffect(board, tgtPos, facing);
    }
}