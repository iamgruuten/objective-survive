//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

#include "CoordinateMap.h"
#include "VHashMap.cpp"
#include "Vec2D.h"

//Initalize CoordinateMap that holds a hashmap
//pre: None
//Post: None
template <typename T>
CoordinateMap<T>::CoordinateMap() : VHashMap<Vec2D, T>(144+1) {}
// 144+1 is a square grid 12 tiles wide, the default board size

//Deconsctructor of coordinateMap
//pre: None
//Post: None
template <typename T>
CoordinateMap<T>::~CoordinateMap() {
    // Destructor.
}

//Hash Function
//pre: None
//Post: None
template <typename T>
int CoordinateMap<T>::hash(Vec2D pos) {
    return ( (int) pos ) % getCapacity();
}

//Insert objects such as space to initialize the map
//pre: None
//Post: New objects is added to hashmap
template <typename T>
void CoordinateMap<T>::add(Vec2D key, T val) {
    VHashMap<Vec2D, T>::add(key, val);
}

//Remove object from key
//pre: Key must exist in the VHashmap
//Post: Objects are removed from hashmap
template <typename T>
void CoordinateMap<T>::remove(Vec2D key) {
    VHashMap<Vec2D, T>::remove(key);
}

//Set object from key
//pre: Key must exist in the VHashmap
//Post: Objects are updated from hashmap
template <typename T>
void CoordinateMap<T>::set(Vec2D key, T val) {
    VHashMap<Vec2D, T>::set(key, val);
}

//Get object from key
//pre: Key must exist in the VHashmap
//Post: None
template <typename T>
T* CoordinateMap<T>::get(Vec2D key) {
    return VHashMap<Vec2D, T>::get(key);
}

//Check if hashmap is empty
//pre: None
//Post: None
template <typename T>
bool CoordinateMap<T>::isEmpty() {
    return VHashMap<Vec2D, T>::isEmpty();
}

//Get size of the hashmap
//pre: None
//Post: None
template <typename T>
int CoordinateMap<T>::getSize() {
    return VHashMap<Vec2D, T>::getSize();
}

//Get capacity of the hashmap
//pre: None
//Post: None
template <typename T>
int CoordinateMap<T>::getCapacity() {
    return VHashMap<Vec2D, T>::getCapacity();
}