#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<VArray.h>

template<class T>
class HeapPriorityQueue
{
    public:
        HeapPriorityQueue<T> (bool (*comp)(T obj1, T obj2));
        //return true if the Max Heap is empty, true otherwise.
        bool isEmpty();
        //used to insert an item in the priority queue.
        void insert(T obj);
        //deletes the highest priority item currently in the queue.
        void remove();
        //return the highest priority item currently in the queue.
        T getTop();
    private:
        //return true if obj1 compares less than obj2
        bool (*compare)(T obj1, T obj2);
        VArray<T> heap;
        void heapifyUp(int idx);
        void heapifyDown(int idx);
        int leftChild(int i)
        {
            return 2*i + 1;
        }
        int rightChild(int i)
        {
            return 2*i + 2;
        }
        int parent(int i)
        {
            return (i-1)/2;
        }
};

#endif