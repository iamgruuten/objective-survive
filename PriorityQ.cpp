#pragma once
#include<string>
#include<iostream>
#include "PriorityQ.h"

void PriorityQ::swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int PriorityQ::get_right_child(int ArrayQ[], int index){
    if((((2*index)+1) < array_size) && (index >= 1))
    {
        return (2*index)+1;
    }
    return -1;
}

int PriorityQ::get_left_child(int ArrayQ[], int index){
    if(((2*index) < array_size) && (index >= 1))
    {
        return 2*index;
    }
    return -1;
}

int PriorityQ::get_parent(int ArrayQ[], int index){
    if ((index > 1) && (index < array_size)) {
        return index/2;
    }
    return -1;
}

void PriorityQ::max_heapify(int ArrayQ[], int index){
    int left = get_left_child(ArrayQ, index);
    int right = get_right_child(ArrayQ, index);

    //Get the maximum in the array for left and right child
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
        
    }
}