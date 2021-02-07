//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef varray_cpp
#define varray_cpp

#include "VArray.h"
#include <stdexcept>
#include <iostream>

template <typename T>
VArray<T>::VArray() {
    size = 0;
    capacity = 1;
    items = new T[1];
}

template <typename T>
VArray<T>::VArray(int initialSize, int initialCapacity) {
    size = initialSize;
    capacity = initialCapacity;
    items = new T[initialCapacity];
}

template <typename T>
VArray<T>::~VArray() {
    // Deconstructor
}

template <typename T>
void VArray<T>::resize() {
    // allocate temp array with larger capacity
    T* temp = new T[2*capacity];

    // copy all elements over from previous array
    for(int i=0;i<capacity;i++) {
        temp[i] = items[i];
    }

    // swap arrays and deallocate temp array
    capacity *= 2;
    T* swap = items;
    items = temp;
    delete[] swap;
}

template <typename T>
void VArray<T>::push(T item) {
    // IF size is equal to capacity, resize array first
    if(size == capacity && capacity < 999) {
        resize();
    }

    // REGARDLESS, insert new element at end, increment size
    items[size] = item;
    size ++;
}

template <typename T>
void VArray<T>::push(T item, int index) {
    // GUARD index < size
    if(index > size || index < 0 && size+index < 0) {
        throw std::out_of_range("OUT OF RANGE");
    }

    // deal with negative indices
    if(index < 0) { index = size+index; }

    // store original index of right most element
    int rightmost = size-1;

    // IF size is equal to capacity, resize array first
    if(size == capacity) {
        resize();
    }

    // REGARDLESS, shift all elements at and after index to the right, one element to the right (up to original capacity for efficiency after resizing)
    for(int i=rightmost; i>=index;i--) {
        items[i+1] = items[i];
    }

    // FINALLY, insert item at index
    items[index] = item;
    size ++;
}

template <typename T>
void VArray<T>::set(T item, int index) {
    // GUARD index < size
    if(index >= size || index < 0 && size+index < 0) {
        throw std::out_of_range("OUT OF RANGE");
    }

    // deal with negative indices
    if(index < 0) { index = size+index; }

    items[index] = item;
}

template <typename T>
T& VArray<T>::get(int index) {
    // GUARD index < size
    if(index >= size || index < 0 && size+index < 0) {
        throw std::out_of_range("OUT OF RANGE");
    }

    // deal with negative indices
    if(index < 0) { index = size+index; }
    
    // THEN return item within size at index
    return items[index];
}

template <typename T>
void VArray<T>::remove(int index) {
    // GUARD index < size
    if(index >= size || index < 0 && size+index < 0) {
        throw std::out_of_range("OUT OF RANGE");
    }

    // deal with negative indices
    if(index < 0) { index = size+index; }
    
    // THEN shift all elements at and to the right of index, one element to the left
    for(int i=index; i<size; i++) {
        items[i] = items[i+1];
    }

    // FINALLY, update size
    size --;
}

template <typename T>
int VArray<T>::getSize() {
    return size;
}

template <typename T>
int VArray<T>::getCapacity() {
    return capacity;
}

template <typename T>
void VArray<T>::print() {
    for(int i=0; i<size-1; i++) {
        std::cout << items[i] << ", ";
    }
    std::cout << items[size-1] << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

template <typename T>
T& VArray<T>::operator[](int index) const {
    return get(index);
}

template <typename T>
typename VArray<T>::Proxy VArray<T>::operator[](int index) {
    return Proxy(*this, index);
}

// Proxy implementations

template <typename T>
VArray<T>::Proxy::operator T() const {
    return varray.get(index);
}

template <typename T>
typename VArray<T>::Proxy& VArray<T>::Proxy::operator=(T value) {
    varray.set(value, index);
    return *this;
}

#endif