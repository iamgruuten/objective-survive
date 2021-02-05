#include "BinaryHeap.h"
#include <iostream>

template <typename T>
void HeapQ<T>::setLeftChild(HeapQ *left){
    leftchild = left;
}

template <typename T>
void HeapQ<T>::setRightChild(HeapQ *right){
    rightchild = right;
}


template <typename T>
void BinaryHeap<T>::heapify_up(){

}

template <typename T>
void BinaryHeap<T>::heapify_down(){

}

template <typename T>
void BinaryHeap<T>::insert(T value){
    HeapQ* newNode = new HeapQ;
    newNode->value = value;

}

template <typename T>
void BinaryHeap<T>::extract(){

}

template <typename T>
bool BinaryHeap<T>::isEmpty(){
    return size == 0;
}

template <typename T>
T& BinaryHeap<T>::insert_extract(){

}

template <typename T>
void BinaryHeap<T>::remove(int index){

}

template <typename T>
void BinaryHeap<T>::increase_key(int index, T key){
    while((index > 1) && ())
}

template <typename T>
void BinaryHeap<T>::decrease_key(int index, T key){

}