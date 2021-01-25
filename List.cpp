#include "List.h"	
#include <cstddef>  
#include <new>      


List::List()
{
	firstNode = NULL;
	size = 0;
}


bool List::add(ItemType newItem)
{
	
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;		
		temp->next = newNode;		
	}

	size++;

	return true;  
}


bool List::add(int index, ItemType newItem)
{
	bool success = (index >= 0) && (index <= size);

	if (success)
	{
		
		Node* newNode = new Node;
		newNode->item = newItem;
		newNode->next = NULL;

		if (index == 0) 
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 1; i < index - 1; i++)
				temp = temp->next;		

			newNode->next = temp->next;	
			temp->next = newNode;		
		}
		size++;
	}

	return success;
}


void List::remove(int index)
{
	bool success = (index >= 0) && (index <= size - 1) && (size != 0);
	if (success)
	{
		Node* tmp = firstNode;
		if (index == 0) 
			firstNode = firstNode->next;
		else
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->next;		
			}

			previous->next = current->next;	
		}		                                
		delete tmp;
		tmp = NULL;
		size--;  
	}
}


ItemType List::get(int index)
{
	ItemType dataItem = -1;
	bool success = (index >= 0) && (index <= size - 1);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;		

		dataItem = current->item;
	}

	return dataItem;
}


bool List::isEmpty()
{
	return size == 0;
}


int List::getLength()
{
	return size;
}


void List::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << temp->item << "\t";
			temp = temp->next;		
		}
	}
}


void List::sortedInsert(ItemType item)
{
	
}


List::Node* List::sortedMerge(Node*& a, Node*& b) 
{
	
	
}