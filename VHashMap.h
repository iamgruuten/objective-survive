//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef vhashmap_h
#define vhashmap_h
#include "VArray.h"

const float VHM_MAX_LOAD_FACTOR = 0.75;

template <class Key, class Value>
struct VHashMapItem {
    Key key;
    Value value;
    VHashMapItem *next;

    VHashMapItem() {}
    VHashMapItem(Key newKey, Value newVal) : key(newKey), value(newVal) {}
};

template <class Key, class Value>
class VHashMap {
private:
    int capacity;
    int size;
    VArray< VHashMapItem<Key, Value>* > *items;

    void initialiseToNullptr();
    void checkLoadAndResize();
public:
    VHashMap();
    VHashMap(int initialCapacity);
    virtual ~VHashMap();
    virtual int hash(Key key) = 0;

    void add(Key newKey, Value newVal);
    void remove(Key existingKey);
    void set(Key existingKey, Value newVal);
    Value* get(Key existingKey);
    bool isEmpty();
    int getSize();
    int getCapacity();
};

#endif