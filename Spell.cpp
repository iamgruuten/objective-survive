#include "Spell.h"
#include "Vec2D.h"
#include "EffectClasses.h"
#include "VArray.cpp"

Spell::Spell() {
    range = 0;
    effects = new VArray<Effect*>;
}

Spell::~Spell() {
    delete effects;
}

void Spell::addEffect(Effect* effect) {
    effects->push(effect);
}

void Spell::activateSpell(Board& board, Vec2D tgtPos, int rotations) {
    for(int i=0; i<effects->getSize(); i++) {
        effects->get(i)->applyEffect(board, tgtPos, rotations);
    }
}