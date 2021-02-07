//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef coordinatemap_h
#define coordinatemap_h
#include "VHashMap.h"

// Forward Declaration
class Vec2D;

template <typename T>
class CoordinateMap : public VHashMap<Vec2D, T> {
private:
public:
    CoordinateMap();
    ~CoordinateMap();

    int hash(Vec2D coord);

    // generic super methods
    void add(Vec2D key, T val);
    void remove(Vec2D key);
    void set(Vec2D key, T val);
    T* get(Vec2D key);
    bool isEmpty();
    int getSize();
    int getCapacity();
};

#endif