#ifndef max_heap_h
#define max_heap_h
#define NULL 0

template <typename T>
class HeapQ{
private:
    HeapQ* leftchild;
    HeapQ* rightchild;
    T value;
public:
    HeapQ(T value) : leftchild(NULL), rightchild(NULL);
    HeapQ():leftchild(NULL), rightchild(NULL), value(NULL){}
    void setLeftChild(HeapQ *left);
    void setRightChild(HeapQ *right);
};


template <typename T>
class BinaryHeap{

private:
    HeapQ* parent;
    int size;

public:
    BinaryHeap() : size(0), parent(0) {}
    void heapify_up();
    void heapify_down();
    void insert(T value);

    void extract();
    T& insert_extract();

    void remove(int index);
    bool isEmpty();
    void increase_key(int index, T key);
    void decrease_key(int index, T key);
};

#endif  

