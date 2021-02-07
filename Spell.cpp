//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

#include "Spell.h"
#include "Vec2D.h"
#include "EffectClasses.h"
#include "VArray.cpp"

Spell::Spell() : effects(new VArray<Effect*>) {
    range = 1;
}

Spell::Spell(int range) : effects(new VArray<Effect*>), range(range) {}

Spell::~Spell() {
    delete effects;
}

void Spell::addEffect(Effect* effect) {
    if(effects != nullptr) {
        effects->push(effect);
    }
}

void Spell::activateSpell(Board& board, Vec2D tgtPos, int rotations) {
    if(effects != nullptr) {
        for(int i=0; i<effects->getSize(); i++) {
            effects->get(i)->applyEffect(board, tgtPos, rotations);
        }
    }
}