#ifndef varray_h
#define varray_h

typedef int ItemType;
template <typename T>
class PriorityQ {

private:
    int array_size;
    int heap_size;
    const int INF;
    T* keys;


public:
PriorityQ() : array_size(20), heap_size(0), INF(1000000) {}
void swap(int *a, int *b){}
int get_right_child(int ArrayQ[], int index){}
int get_left_child(int ArrayQ[], int index){}
int get_parent(int ArrayQ[], int index){}
void max_heapify(int ArrayQ[], int index){}
void build_max_heap(int ArrayQ[]){}
int maximum(int ArrayQ[]){}
int get_max(int ArrayQ[]){}

void increase_key(int ArrayQ[], int index, T key){}
void decrease_key(int ArrayQ[], int index, T key){}
void insert(int ArrayQ[], T key){}
void print_heap(int ArrayQ[]){}

};

#endif