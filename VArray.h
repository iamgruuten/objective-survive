#ifndef varray_h
#define varray_h

template <typename T>
class VArray {
private:    
    int size;
    int capacity;
    T* items;

public:
    VArray();
    VArray(int initialCapacity);
    ~VArray();
    void resize();
    void push(T item);
    void push(T item, int index);
    void replace(T item, int index);
    T get(int index);
    T getLast();
    void remove(int index);
    int getSize();
    int getCapacity();
    void print();
};

#endif