#ifndef bhpriorityqueue_h
#define bhpriorityqueue_h
#include "VArray.h"

// NOTE: min-heap implementation

template <typename T>
struct BHNode {
    int priority;
    T val;
};

template <typename T>
class BHPriorityQueue {
private:
    VArray<BHNode<T>* > queue;

    // convenience methods
    int getParentIndex(int childIndex);
    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    void swap(int nodeIndexA, int nodeIndexB);
    void recursiveUpHeap(int nodeIndex);
    void recursiveDownHeap(int nodeIndex);

public:
    BHPriorityQueue() : queue() {}
    BHPriorityQueue(VArray<BHNode<T> > nodes);
    ~BHPriorityQueue();

    // heap methods
    void insert(int priority, T val);
    T extract();
    T peek();
    T insertExtract(int priority, T val);
    int search(T val);
    void remove(T val);
    void print();
};

#endif