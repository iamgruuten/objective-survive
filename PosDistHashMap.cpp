#include "PosDistHashMap.h"
#include "VHashMap.cpp"
#include "PositionClasses.h"

PosDistHashMap::PosDistHashMap() : VHashMap<AbsolutePosition, int>(144+1) {}

PosDistHashMap::~PosDistHashMap() {}

// https://en.wikipedia.org/wiki/Pairing_function
// "...uniquely encodes two natural numbers into a single natural number."
int cantor_pairing_function(float x, float y) {
    return (int) (0.5 * (x + y) * (x + y + 1)) + 1;
}

int PosDistHashMap::hash(AbsolutePosition absPos) {
    return cantor_pairing_function(absPos.x, absPos.y) % getCapacity();
}

void PosDistHashMap::add(AbsolutePosition newKey, int newVal) {
    VHashMap::add(newKey, newVal);
}

void PosDistHashMap::remove(AbsolutePosition existingKey) {
    VHashMap::remove(existingKey);
}

void PosDistHashMap::set(AbsolutePosition existingKey, int newVal) {
    VHashMap::set(existingKey, newVal);
}

int* PosDistHashMap::get(AbsolutePosition existingKey) {
    return VHashMap::get(existingKey);
}

bool PosDistHashMap::isEmpty() {
    return VHashMap::isEmpty();
}

int PosDistHashMap::getSize() {
    return VHashMap::getSize();
}

int PosDistHashMap::getCapacity() {
    return VHashMap::getCapacity();
}