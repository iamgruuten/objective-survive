#include "Spell.h"
#include "PositionClasses.h"
#include "EffectClasses.h"
#include "VArray.cpp"

Spell::Spell() {
    range = 0;
}

void Spell::addEffect(Effect* effect) {
    effects.push(effect);
}

void Spell::activateSpell(Board& board, int distance, Directions facing, AbsolutePosition origin) {
    RelativePosition relPos = RelativePosition(0, distance);
    AbsolutePosition pivot = AbsolutePosition(0,0);
    RotationHandler::rotateToFace(relPos, &pivot, up, facing);
    AbsolutePosition tgtPos = relPos.getAbsolutePos(origin);

    for(int i=0; i<effects.getSize(); i++) {
        effects.get(i)->applyEffect(board, tgtPos, facing);
    }
}