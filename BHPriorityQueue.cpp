//Team members - Lee Quan Sheng and Eugene Long
//Group 8
//Priority Queue using Binary Heap
//Min Heap
/**
The Binary Heap Priority Queue uses VArray implementation
Time Complexity: The time complexity of all the operation is O(log N) except for GetMin() which has time complexity of O(1). 
Auxiliary Space: O(N)
**/

#include "BHPriorityQueue.h"
#include "VArray.cpp"
#include <iostream>

//This function takes in VArray (which is used across most applications) to intilalize with its initial binary heap
//pre: None
//Post: Returns a initialize BHPQ with the VArrays
//https://en.wikipedia.org/wiki/Binary_heap
template <typename T>
BHPriorityQueue<T>::BHPriorityQueue(VArray<BHNode<T> > nodes) {
    // copy all nodes into queue
    for(int i=0; i<nodes.getSize(); i++) {
        insert(&nodes.get(i));
    }
}

//Desconstructor of BinaryHeapPriorityQueue
//pre: None
//Post: None
template <typename T>
BHPriorityQueue<T>::~BHPriorityQueue() {}

//This function retrieve the parent index of child index
//pre: ChildIndex must exist for its parent
//Post: Returns parent index
template <typename T>
int BHPriorityQueue<T>::getParentIndex(int childIndex) {
    return floor( (childIndex - 1) / 2 );
}

//This function retrieve the left child index of the parent index
//pre: parentIndex must exist 
//Post: Return left child index of parent
template <typename T>
int BHPriorityQueue<T>::getLeftChildIndex(int parentIndex) {
    return (2 * parentIndex) + 1;
}

//This function retrieve the right child of the parent index
//pre: parentIndex must exist 
//Post: Return right child index of parent
template <typename T>
int BHPriorityQueue<T>::getRightChildIndex(int parentIndex) {
    return (2 * parentIndex) + 2;
}

//This function is to swap the node between both nodes
//pre: Both nodes must exist
//Post: None
template <typename T>
void BHPriorityQueue<T>::swap(int nodeIndexA, int nodeIndexB) {

    // swap child with its parent
    BHNode<T> *temp = queue.get(nodeIndexB);
    queue.set(queue.get(nodeIndexA), nodeIndexB); // b = a
    queue.set(temp, nodeIndexA); // a = b(old)
}

//Known as heapify up, Swapping the value upwards
//pre: the index of the node must exist to swap up
//Post: the index of the node is swapped upwards
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

//Known as heapify down, Swapping the value downwards
//pre: the index of the node must exist to swap down
//Post: The index of the node is swapped downwards
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

//Insert Value to BHPQ
//pre: None
//Post: New item is added to BHPQ
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

//Extracting the min heap aka parentNode of BHPQ
//pre: BHPQ must contain at least 1 values
//Post: Return and Removes Top Node (Min Heap) 
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

//Get Top Value
//pre: BHPQ must contain at least 1 values
//Post: Returns top value (Min-Heap)
template <typename T>
T BHPriorityQueue<T>::peek() {
    // get val at front of queue
    return queue.get(0)->val;
}

//Insert and Extract the min heap aka parentNode of BHPQ
//pre: BHPQ must contain at least 1 values
//Post: Insert new value. Return and Removes Top Node (Min Heap)
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

//Search for arbitrary element
//pre: None
//Post: Return searched result
template <typename T>
int BHPriorityQueue<T>::search(T val) {
    for(int i=0; i<queue.getSize(); i++) {
        if(queue.get(i)->val == val) {
            return i;
        }
    }
    return -1; // not found
}

//Print BHPQ in a priority level
//pre: None
//Post: None
template <typename T>
void BHPriorityQueue<T>::print() {
    for(int i=0; i<queue.getSize(); i++) {
        BHNode<T> *ptr = queue.get(i);
        std::cout << "Priority: " << ptr->priority << ", Val: " << ptr->val << std::endl;
    }
    std::cout << std::endl;
}

//Get size of BHPQ
//pre: None
//Post: None
template <typename T>
int BHPriorityQueue<T>::getSize() {
    return queue.getSize();
}


//Checks if BHPQ is empty
//pre: None
//Post: None
template <typename T>
bool BHPriorityQueue<T>::isEmpty() {
    return getSize() == 0;
}