#include "Queue.h"
#define NULL 0

template <typename T>
Queue<T>::~Queue() {
    while(!isEmpty()) {
        dequeue();
    }
}

template <typename T>
bool Queue<T>::enqueue(T value) {
    QueueNode<T> *node = new QueueNode<T>();
    node->item = value;

    if(isEmpty()) {
        front = node;      
    } else {
        back->next = node;
    }
    back = node;

    return true;
}

template <typename T>
bool Queue<T>::dequeue() {
    if(!isEmpty()) {
        QueueNode<T> *temp = front;
        front = front->next;
        delete temp;
    }
    else {
        return false;
    }
}

template <typename T>
T Queue<T>::popFront() {
    T val;
    if(!isEmpty()) {
        val = front->item;
        dequeue();
    }
    return val;
}

template <typename T>
T Queue<T>::getFront() {
    T val;
    if(!isEmpty()) {
        val = front->item;
    }
    return val;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return front == NULL;
}