#ifndef BinaryHeapPQ_h
#define BinaryHeapPQ_h

#include "VArray.h"

template <typename T>
struct Node {
  int key;
  T value;
  int position;
} ;

template <typename T>
class BinaryHeapPQ {
 public:
  BinaryHeapPQ(VArray<Node<T> >);  
  void printqueue();
  Node<T>* deletemin();
  void decreasekey(Node<T> x);
  void changevalue(int i, T value);
  Node<T> getnode(int i);
  int size();

 private:
  VArray<Node<T>> makeheap(VArray<Node<T>> S);
  VArray<Node<T>> mHeap;
  int minchild(int i);
  void heapifyDown(Node<T> x, int i);
  void heapifyUp(Node<T> x, int i);
 
};


#endif