#include "BinaryHeapPQ.h"
#include "VArray.cpp"
#include <iostream>

template <typename T>
BinaryHeapPQ<T>::BinaryHeapPQ(VArray< Node<T> > node) : mHeap(node) {
    for(int index = node.getSize()-1; index >= 0; index--){
        heapifyDown(mHeap.get(index), index);
    }
}

template <typename T>
void BinaryHeapPQ<T>::changevalue(int index, T value){
    mHeap.set(value, index);
}

//Return index of smallest child of min heap
template <typename T>
int BinaryHeapPQ<T>::minchild(int index){
    
  if(2*index+1 >= mHeap.getSize()){ 
      //if the index is more than halfway through the array
    return 0; //no children
  }
  else{ 
      //otherwise, if the index is in the first half of the array
    if(2*index+2 >= mHeap.getSize()){
        return 2 * index + 1; //there is only 1 child, so return it
    }
    else{
        //if there is more than 1 child
      if(mHeap.get(2*index+1).value < mHeap.get(2*index+2).value){
	    return 2*index+1;
	}
	else{
	  return 2*index+2;
	}     
    }
  }
}

template <typename T>
void BinaryHeapPQ<T>::heapifyDown(Node<T> nodeV, int index){
  int currentIndex = minchild(index);
  while(currentIndex != 0 && mHeap.get(currentIndex).value < nodeV.value){
    Node<T> temp = mHeap.get(index);
    mHeap.get(currentIndex) = index; 

    mHeap.get(index).position = index;
    mHeap.get(currentIndex) = temp; 
    mHeap.get(currentIndex).position = currentIndex;
    index = currentIndex;
    currentIndex = minchild(index);
  } 

  mHeap.get(index) = nodeV;
  mHeap.get(index).position = index;
}

template <typename T>
void BinaryHeapPQ<T>::heapifyUp(Node<T> nodeV, int index){
    int p = index >> 1;

    while(index != 0 && mHeap.get(p).value > nodeV.value){
        Node<T> temp = mHeap.get(index);
        mHeap.get(index) = mHeap.get(p); 
        mHeap.get(index).position = index;
        mHeap.get(p) = temp;
        mHeap.get(p).position = p;

        index = p;
        p = index >> 1;
    }
}

//Remove and extract minimum
template <typename T>
Node<T>* BinaryHeapPQ<T>::deletemin() {
  if(mHeap.getSize() == 0){
    return 0;
  }
  else{
    Node<T> a = mHeap.get(0);
    heapifyDown(mHeap.get(mHeap.getSize() - 1), 0);
    mHeap.remove(mHeap.getSize() - 1);
    return &a;
  }
}

template <typename T>
void BinaryHeapPQ<T>::decreasekey(Node<T> nodeV){
  heapifyUp(nodeV, nodeV.position);
}

template <typename T>
Node<T> BinaryHeapPQ<T>::getnode(int index){
  return mHeap.get(index);
  
}

template <typename T>
int BinaryHeapPQ<T>::size(){
  return mHeap.getSize();
}

template <typename T>
void BinaryHeapPQ<T>::printqueue(){
  for(int index = 0; index < mHeap.getSize(); index++){
    std::cout << "key: " << mHeap.get(index).key << " value: " << mHeap.get(index).value << " position: " << mHeap.get(index).position << std::endl;
  }
}