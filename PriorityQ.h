#pragma once
#include<string>
#include<iostream>

typedef int ItemType;

class PriorityQ {
private:
    struct Node
    {
        ItemType item;
        Node* next;
    }

    Node* frontNode;
    Node* backNode;

public:



};