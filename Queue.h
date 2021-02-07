//Group 8
//Lee Quan Sheng [S10198298], Eugene Long [S10193060J]

// Queue

// This is a general templated Queue class
// that can be used flexibly within the program.

// Originally intended for use in level-order graph
// traversal, but has seen much use otherwise.

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
    
    //Enqueue value to queue
    //pre: None
    //Post: The new value is insert to the end 
    bool enqueue(T value);

    //Dequeue value to queue
    //pre: None
    //Post: The top value of the queue is removed
    bool dequeue();

    //Get and Pop front value 
    //pre: None
    //Post: The top value of the queue is removed and returned
    T popFront();

    //Get front value
    //pre: None
    //post: None
    T getFront();

    //Get the size value to queue
    //pre: None
    //Post: None
    int getSize();

    //Checks if the size of the queue is empty
    //pre: None
    //Post: None
    bool isEmpty();
};

#endif