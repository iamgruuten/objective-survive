//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// ! Featured !

// VHashMap

// VHashMap is a dynamic HashMap that resizes itself
// according to its load factor

// The load factor is calculated as n/k, where
// n is the number of entries and k is the number
// of buckets

// It is built on top of the VArray ADT, in place of
// a vector, or implementing its own array resizing
// function

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
    VHashMapItem(Key newKey, Value newVal) : key(newKey), value(newVal), next(0) {}
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

    //Initalize the initialCapacity of the map
    //pre: None
    //Post: None
    VHashMap(int initialCapacity);

    virtual ~VHashMap();

    //Hash Function to get the hash value
    //pre: None
    //Post: None
    virtual int hash(Key key) = 0;

    //Add value to hashmap
    //pre: None
    //Post: The new value is added to VArray by its hash key
    void add(Key newKey, Value newVal);

    //Remove value from Hashmap
    //pre: None
    //Post: The value is remove from the VArray by the indicated hash key
    void remove(Key existingKey);

    //Add value to hashmap
    //pre: None
    //Post: The value is replace in the VArray by the indicated hash key
    void set(Key existingKey, Value newVal);

    //Get value to hashmap
    //pre: None
    //Post: None
    Value* get(Key existingKey);

    //Checks if hashmap is empty
    //pre: None
    //Post: None
    bool isEmpty();

    //Gets size of the hashmap
    //pre: None
    //Post: None
    int getSize();

    //Get Capacity of the hashmap
    //pre: None
    //Post: None
    int getCapacity();
};

#endif