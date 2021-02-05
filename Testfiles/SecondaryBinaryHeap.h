

struct HeapElement {
    int value;
    HeapElement* parent;
    HeapElement* child1;
    HeapElement* child2;
};

class SecondaryBinaryHeap {
    HeapElement* head;
public:
    SecondaryBinaryHeap();
    ~SecondaryBinaryHeap();
    void insert(int value); // inserts value d into the heap
    int top(); // returns the smallest element
    bool pop_top(); // removes the smallest element
 
};