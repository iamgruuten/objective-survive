#include<string>
#include<iostream>
#include "BinaryHeapPQ.h"
#include "VArray.h"

int main(){
    VArray<Node<int>> nodes;
    VArray<int> weights = {5, 8, 5, 18, 18, 17, 19, 21};

    for(int i = 0; i < weights.getSize(); i++){
        Node<int> n;
        n.key = i;
        n.value = weights[i];
        nodes.push(n);
    }
    
    BinaryHeapPQ<> pq = BinaryHeapPQ<>(nodes);
    pq.printqueue();

    pq.deletemin();
    pq.printqueue();

    pq.deletemin();
    pq.printqueue();

    pq.changevalue(4, 0);
    pq.getnode(4);

    pq.printqueue();
}