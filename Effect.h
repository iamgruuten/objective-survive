#ifndef effect_h
#define effect_h
#include "Background.h"
#include "Entity.h"

class Effect {
private:
    RelativePosition effectRelPos;

public:
    Effect();
    Effect(RelativePosition relPos);
    ~Effect();
    virtual void applyEffect(Entity* entity, Direction facing);
};

class DamageEffect: private Effect {
private:
    int damage;
    int knockback;

public:
    DamageEffect();
    DamageEffect(int dmg, int moveDist, RelativePosition relPos);
    ~DamageEffect();
    void applyEffect(Entity* entity, Direction facing);
};

/*
enum StateEffectType {
    setFire, setWet, setAbyss, setSmoke, stun, lockMovement
};

class StateEffect: private Effect {
private:
    int ticks;
    StateEffectType type;

public:
    StateEffect();
    StateEffect(StateEffectType type, RelativePosition relPos);
    ~StateEffect();
    void applyEffect(Entity& entity, int cardinalDirection);
};
*/

#endif