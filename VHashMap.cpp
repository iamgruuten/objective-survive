//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

#include "VHashMap.h"
#include "VArray.cpp"
#include <iostream>

template <class Key, class Value>
void VHashMap<Key, Value>::initialiseToNullptr() {
    for(int i=0; i<capacity; i++) {
        items->set(nullptr, i);
    }
}

template <class Key, class Value>
VHashMap<Key, Value>::VHashMap() {
    size = 0;
    capacity = 16;
    items = new VArray< VHashMapItem<Key, Value>* >(16);
    initialiseToNullptr();
}

template <class Key, class Value>
VHashMap<Key, Value>::~VHashMap() {
    // Deallocate
}

template <class Key, class Value>
VHashMap<Key, Value>::VHashMap(int initCap) {
    size = 0;
    capacity = initCap;
    items = new VArray< VHashMapItem<Key, Value>* >(initCap, initCap);
    initialiseToNullptr();
}

template <class Key, class Value>
void VHashMap<Key, Value>::checkLoadAndResize() {
    int load = (float) ( (float) size / (float) capacity);

    // if load exceeded, increase capacity
    if(load > VHM_MAX_LOAD_FACTOR) {
        items->resize();
    }
}

template <class Key, class Value>
void VHashMap<Key, Value>::add(Key newKey, Value newVal) {
    int index = hash(newKey);

    // increase size, then check load factor and resize before adding new item
    size ++;
    checkLoadAndResize();

    // create new item
    VHashMapItem<Key, Value> *item = new VHashMapItem<Key, Value>(newKey, newVal);

    // insert item into hashmap after resizing
    VHashMapItem<Key, Value> *bucket = items->get(index);
    if(bucket == nullptr) {
        items->set(item, index);
    } else {
        VHashMapItem<Key, Value> *temp = bucket;

        // travesrse to end of linked list
        while(true) {
            // check for duplicate keys while we travel
            if(temp->key == newKey) {
                // reject insertion of duplicate key!
                size--;
                return;
            }

            if(temp->next != nullptr) {
                temp = temp->next;
            } else {
                break;
            }
        }

        // append item to bucket
        temp->next = item;
    }
}

template <class Key, class Value>
void VHashMap<Key, Value>::remove(Key existingKey) {
    // GUARD hashmap size is more than zero
    if(isEmpty()) {
        return;
    }

    int index = hash(existingKey);

    VHashMapItem<Key, Value> *temp = items->get(index);
    VHashMapItem<Key, Value> *prevItem = nullptr;

    // search for item with matching key
    while(temp != nullptr) {
        if(temp->key == existingKey) {
            // match found

            // stitch proceeding items to prev item,
            if(prevItem != nullptr) {
                prevItem->next = temp->next;
            } else {
                // deleting head of linked list
                items->set(temp->next, index);
            }

            // now that item has been extracted safely,
            // delete item and reduce size.
            size --;
            delete temp;
            return;
        }

        // else, continue traversing linked list
        prevItem = temp;
        temp = temp->next;
    }

    // if not found, entry does not exist
}

template <class Key, class Value>
void VHashMap<Key, Value>::set(Key existingKey, Value newVal) {
    int index = hash(existingKey);

    VHashMapItem<Key, Value> *temp = items->get(index);

    // search for item with matching key
    while(temp != NULL) {
        if(temp->key == existingKey) {
            temp->value = newVal;
        }

        // else, continue traversing linked list
        temp = temp->next;
    }

    // no matching key in linked list, add new item
    add(existingKey, newVal);
}

template <class Key, class Value>
Value* VHashMap<Key, Value>::get(Key existingKey) {
    int index = hash(existingKey);

    VHashMapItem<Key, Value> *temp = items->get(index);

    // search for item with matching key
    while(temp != nullptr) {
        if(temp->key == existingKey) {
            return &(temp->value);
        }

        // else, continue traversing linked list
        temp = temp->next;
    }

    return NULL;
}

template <class Key, class Value>
bool VHashMap<Key, Value>::isEmpty() {
    return size == 0;
}

template <class Key, class Value>
int VHashMap<Key, Value>::getSize() {
    return size;
}

template <class Key, class Value>
int VHashMap<Key, Value>::getCapacity() {
    return capacity;
}