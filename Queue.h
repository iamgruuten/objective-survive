#ifndef queue_h
#define queue_h

template <typename T>
struct QueueNode {
    T item;
    QueueNode *next;
};

template <typename T>
class Queue {
private:
    int size;
    QueueNode<T> *front;
    QueueNode<T> *back;
public:
    Queue() : size(0), front() {}
    ~Queue();
    bool enqueue(T value);
    bool dequeue();
    T popFront();
    T getFront();
    bool isEmpty();
};

#endif