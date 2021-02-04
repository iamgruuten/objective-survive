#pragma once
#include<string>
#include<iostream>

typedef int ItemType;

class PriorityQ {

private:
    int array_size;
    int heap_size;
    const int INF;

public:
PriorityQ() : array_size(20), heap_size(0), INF(1000000) {}
void swap(int *a, int *b){}
int get_right_child(int A[], int index){}
int get_left_child(int A[], int index){}
int get_parent(int A[], int index){}
void max_heapify(int A[], int index){}
void build_max_heap(int A[]){}
int maximum(int A[]){}
int get_max(int A[]){}
void increase_key(int A[], int index, int key){}
void decrease_key(int A[], int key){}
void print_heap(int A[]){}

};