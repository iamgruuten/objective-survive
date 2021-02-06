//Team members - Lee Quan Sheng and Eugene Long
//Group 8

#ifndef varray_h
#define varray_h

template <typename T>
class VArray {
friend class Proxy;
private:    
    int size;
    int capacity;
    T* items;

public:
    // Proxy class for [] operators
    class Proxy {
        friend class VArray;
        private:
            VArray& varray;
            int index;
        public:
            // uses an initialisation list to load values into proxy variables before constructor/methods run
            Proxy(VArray& varray, int index) : varray(varray), index(index) {}

            // operators
            operator T() const; // rvalue get
            Proxy& operator=(T value); // set
    };

    VArray();
    VArray(int initialSize, int initialCapacity);
    ~VArray();
    void resize();
    void push(T item);
    void push(T item, int index);
    void set(T item, int index);
    T& get(int index);
    void remove(int index);
    int getSize();
    int getCapacity();
    void print();

    // operator methods
    T& operator[](int index) const; // rvalue get
    Proxy operator[](int index); // cast to proxy for other operands
};

#endif