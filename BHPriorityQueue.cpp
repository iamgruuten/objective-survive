//Team members - Lee Quan Sheng and Eugene Long
//Group 8
//Priority Queue using Binary Heap
//Min Heap

#include "BHPriorityQueue.h"
#include "VArray.cpp"
#include <iostream>

template <typename T>
BHPriorityQueue<T>::BHPriorityQueue(VArray<BHNode<T> > nodes) {
    // copy all nodes into queue
    for(int i=0; i<nodes.getSize(); i++) {
        insert(&nodes.get(i));
    }
}

template <typename T>
BHPriorityQueue<T>::~BHPriorityQueue() {
    
}

template <typename T>
int BHPriorityQueue<T>::getParentIndex(int childIndex) {
    return floor( (childIndex - 1) / 2 );
}

template <typename T>
int BHPriorityQueue<T>::getLeftChildIndex(int parentIndex) {
    return (2 * parentIndex) + 1;
}

template <typename T>
int BHPriorityQueue<T>::getRightChildIndex(int parentIndex) {
    return (2 * parentIndex) + 2;
}

template <typename T>
void BHPriorityQueue<T>::swap(int nodeIndexA, int nodeIndexB) {

    // swap child with its parent
    BHNode<T> *temp = queue.get(nodeIndexB);
    queue.set(queue.get(nodeIndexA), nodeIndexB); // b = a
    queue.set(temp, nodeIndexA); // a = b(old)
}

template <typename T>
void BHPriorityQueue<T>::recursiveUpHeap(int nodeIndex) {
    // base case: parent value <= child or node is top element (index 0)
    if(nodeIndex == 0) {
        return;
    }

    int parentIndex = getParentIndex(nodeIndex);
    if(queue.get(parentIndex)->priority <= queue.get(nodeIndex)->priority) {
        return;
    }

    // else, swap parent and child and call this function again on the parent's pos
    swap(nodeIndex, parentIndex);
    recursiveUpHeap(parentIndex);
}

template <typename T>
void BHPriorityQueue<T>::recursiveDownHeap(int nodeIndex) {
    // base case: node is larger than both its children for all levels of the heap
    int size = queue.getSize();
    int smallest = nodeIndex;

    // check left and swap if required
    int leftIndex = getLeftChildIndex(nodeIndex);
    if(leftIndex < size && queue.get(leftIndex)->priority < queue.get(smallest)->priority) {
        smallest = leftIndex;
    }

    // check right and swap if required
    int rightIndex = getRightChildIndex(nodeIndex);
    if(rightIndex < size && queue.get(rightIndex)->priority < queue.get(smallest)->priority) {
        smallest = rightIndex;
    }

    // check smallest, if smallest is updated, swap root with smallest child
    // then, continue recursively checking downwards
    if(smallest != nodeIndex) {
        swap(nodeIndex, smallest);
        recursiveDownHeap(smallest);
    }
}

//Psuedocode
/**Add the element to the bottom level of the heap at the leftmost open space.
Compare the added element with its parent; if they are in the correct order, stop.
If not, swap the element with its parent and return to the previous step.**/

template <typename T>
void BHPriorityQueue<T>::insert(int priority, T val) {
    // insert element at the leftmost open space (end of the array)
    BHNode<T> *newNode = new BHNode<T>();
    newNode->priority = priority;
    newNode->val = val;
    queue.push(newNode);

    // only do up-heaping if parents exist
    if(queue.getSize() > 1) {
        // recursively up-heap (swap child with parent until heap order is restored)
        // in this case, the child index is the last element in the array (size -1)
        recursiveUpHeap(queue.getSize()-1);
    }
}

//Psuedocode
/**
Replace the root of the heap with the last element on the last level.
Compare the new root with its children; if they are in the correct order, stop.
If not, swap the element with one of its children and return to the previous step. (Swap with its smaller child in a min-heap and its larger child in a max-heap.)
**/

template <typename T>
T BHPriorityQueue<T>::extract() {
    // GUARD queue has elements
    int size = queue.getSize();
    if(size == 0) {
        
        throw std::out_of_range("OUT OF RANGE");
    }

    // get return value before root gets removed
    T retVal = peek();

    // delete root safely by swapping it with last node (in level order, or size -1 pos), then removing the last node
    swap(0, size-1);
    queue.remove(size-1);

    // downwawrds heapify new root to maintain heap (since one of the largest values is now at the top, it should 'sink' to a lower level)
    recursiveDownHeap(0);

    // once done, return val
    return retVal;
}

template <typename T>
T BHPriorityQueue<T>::peek() {
    // get val at front of queue
    return queue.get(0)->val;
}

template <typename T>
T BHPriorityQueue<T>::insertExtract(int priority, T val) {
    // GUARD queue has elements
    int size = queue.getSize();
    if(size == 0) {
        throw std::out_of_range("OUT OF RANGE");
    }

    // check if inserted value is smaller than smallest value in heap (root)
    if(val < peek()) {
        // if it's smaller, it would be root after inserting, so it would also be extracted.
        return val;
    }

    // else, just down-heapify from the new val onwards
    T retVal = peek();

    // insert new val at root
    BHNode<T> *newNode = new BHNode<T>();
    newNode->priority = priority;
    newNode->val = val;
    queue.set(*newNode, 0);

    // down heapify
    recursiveDownHeap(0);

    // finally, return val
    return retVal;
}

template <typename T>
void BHPriorityQueue<T>::print() {
    for(int i=0; i<queue.getSize(); i++) {
        BHNode<T> *ptr = queue.get(i);
        std::cout << "Priority: " << ptr->priority << ", Val: " << ptr->val << std::endl;
    }
    std::cout << std::endl;
}