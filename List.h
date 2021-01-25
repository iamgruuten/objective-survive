#pragma once


#include<string>
#include<iostream>
using namespace std;

typedef int ItemType;

class List
{
private:
	struct Node
	{
		ItemType item;	
		Node* next;	
	};

	Node* firstNode;	
	int  size;			

public:

	
	List();

	
	
	
	
	bool add(ItemType newItem);

	
	
	
	
	
	bool add(int index, ItemType newItem);

	
	
	
	
	
	void remove(int index);

	
	
	
	
	ItemType get(int index);

	
	
	
	
	bool isEmpty();

	
	
	
	
	int getLength();

	

	
	void print();

	void sortedInsert(ItemType item);

	Node* sortedMerge(Node*& list1, Node*& list2);
};