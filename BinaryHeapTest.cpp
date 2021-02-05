#include<string>
#include<iostream>
#include "BinaryHeapPQ.h"
#include "BinaryHeapPQ.cpp"
//#include "VArray.cpp"

int main(){
    VArray<Node<int>> nodes;
    VArray<int> weights;
    int arrayA[] = {5, 8, 5, 18, 18, 17, 19, 21};
    for (int i:arrayA){
        weights.push(i);
    }

    for(int i = 0; i < weights.getSize(); i++){
        Node<int> n;
        n.key = i;
        n.value = weights.get(i);
        nodes.push(n);
    }
    
    BinaryHeapPQ<int> pq = BinaryHeapPQ<int>(nodes);
    pq.printqueue();

    pq.deletemin();
    pq.printqueue();

    pq.deletemin();
    pq.printqueue();

    pq.changevalue(4, 0);
    pq.getnode(4);

    pq.printqueue();
}