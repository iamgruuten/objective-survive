#include<string>
#include<iostream>
#include "PriorityQ.h"

template <typename T>
void PriorityQ<T>::swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
template <typename T>
int PriorityQ<T>::get_right_child(int ArrayQ[], int index){
    if((((2*index)+1) < array_size) && (index >= 1))
    {
        return (2*index)+1;
    }
    return -1;
}
template <typename T>
int PriorityQ<T>::get_left_child(int ArrayQ[], int index){
    if(((2*index) < array_size) && (index >= 1))
    {
        return 2*index;
    }
    return -1;
}
template <typename T>
int PriorityQ<T>::get_parent(int ArrayQ[], int index){
    if ((index > 1) && (index < array_size)) {
        return index/2;
    }
    return -1;
}
template <typename T>
void PriorityQ<T>::max_heapify(int ArrayQ[], int index){
    int left = get_left_child(ArrayQ, index);
    int right = get_right_child(ArrayQ, index);

    int max = index;

    if((left <= heap_size) && (left >0)){
        if(ArrayQ[left] > ArrayQ[max]){
            max = left;
        }
    }

    if((right <= heap_size && (right > 0))){
        if((ArrayQ[right] > ArrayQ[max])){
            max = right;
        }
    }

    if(max != index){
      swap(&ArrayQ[index], &ArrayQ[max]);
      max_heapify(ArrayQ, max);  
    }
}
template <typename T>
void PriorityQ<T>::build_max_heap(int ArrayQ[]){

  for(int i=heap_size/2; i>=1; i--) {
    max_heapify(ArrayQ, i);
  }
}
template <typename T>
int PriorityQ<T>::maximum(int ArrayQ[]){
    return ArrayQ[1];
}
template <typename T>
int PriorityQ<T>::get_max(int ArrayQ[]){
    int maxm = ArrayQ[1];
    ArrayQ[1] = ArrayQ[heap_size];

    heap_size = heap_size - 1;
    max_heapify(ArrayQ, 1);
    return maxm;
}

template <typename T>
void PriorityQ<T>::increase_key(int ArrayQ[], int index, T key){
    ArrayQ[index] = key;
    while((index > 1) && (ArrayQ[get_parent(ArrayQ, index)] < ArrayQ[index])) {
        swap(&ArrayQ[index], &ArrayQ[get_parent(ArrayQ, index)]);
        index = get_parent(ArrayQ, index);
    }
}

template <typename T>
void PriorityQ<T>::decrease_key(int ArrayQ[], int index, T key){
    ArrayQ[index] = key;
    max_heapify(ArrayQ, index);

}

template <typename T>
void PriorityQ<T>::insert(int ArrayQ[], T key){
    heap_size = heap_size + 1;
    ArrayQ[heap_size] = -1*INF;
    increase_key(ArrayQ, heap_size, key);
}

template <typename T>
void PriorityQ<T>::print_heap(int ArrayQ[]){

  for(int i = 1; i <= heap_size; i++) {
    printf("%d\n",ArrayQ[i]);
  }
  printf("\n");
}
