#include "PriorityQ.h"

template<class T> HeapPriorityQueue<T>::HeapPriorityQueue(bool (*comp)(T obj1, T obj2))
{
    this -> compare = comp;
}

template<class T> bool HeapPriorityQueue<T>::isEmpty()
{
    return heap.empty();
}

template<class T> void HeapPriorityQueue<T>::insert(T obj)
{
    heap.push(obj);
    heapifyUp(heap.size()-1);
}

template<class T> void HeapPriorityQueue<T>::pop()
{
    if(!isEmpty())
    {
       std::swap(heap[0], heap[heap.size()-1]);
       heap.pop_back();
       if(!isEmpty())
          heapifyDown(0);
    }
}

//TODO Search Implementation
//TODO 

template<class T> T HeapPriorityQueue<T>::getTop()
{
    if(!isEmpty())
    {
       return heap[0];
    }
}

template<class T> void HeapPriorityQueue<T>::heapifyDown(int idx)
{
    int largeIdx = idx;
    int leftChildIdx = leftChild(idx);
    int rightChildIdx = rightChild(idx);
    
    if(leftChildIdx < heap.size())
    {
       if(compare(heap[largeIdx], heap[leftChildIdx]))
            largeIdx = leftChildIdx;
    }
    if(rightChildIdx < heap.size())
    {
       if(compare(heap[largeIdx], heap[rightChildIdx]))
            largeIdx = rightChildIdx;
    }

    if(largeIdx != idx)
    {
       std::swap(heap[largeIdx], heap[idx]);
       heapifyDown(largeIdx);
    }
}

template<class T> void HeapPriorityQueue<T>::heapifyUp(int idx)
{
    int parentIdx = parent(idx);
    if(parentIdx < 0)
            return;
    if(compare(heap[parentIdx], heap[idx]))
    {
        std::swap(heap[parentIdx], heap[idx]);
        heapifyUp(parentIdx);
    }
}
