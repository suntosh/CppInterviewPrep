#include "stdafx.h"
#include <iostream>
#include "LinkedListOps.h"


using namespace std;

struct Node* head;
struct Node* first;
struct Node* second;



void LinkedListTest()
{
	
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));


	head->data = 1;
	head->next = first;
	first->data = 2;
	first->next = second;
	second->data = 3;
	second->next = NULL;

	printlist(head);
	freeAllfromfirst(head);


	
}


void printlist(struct Node* n)
{
	while (n != NULL)
	{
		cout << n->data << endl;
		n = n->next;
	}
}

void freeAllfromlast(struct Node* n)
{
	struct Node* head = n;
	struct Node* tail = n;
	struct Node* previous = NULL;
	int i = 0;
	while (head->next != NULL)
	{
		while (tail->next != NULL)
		{
			previous = tail;
			tail = tail->next;
		}
		previous->next = NULL;
		cout << "Deleting Node " << tail->data << endl;
		free(tail);
		tail = head;
	}
	cout << "Deleting Head Node " << tail->data << endl;
	free(tail);
}

void freeAllfromfirst(struct Node* n)
{
	struct Node* pointer;
	while (n->next != NULL)
	{
		pointer = n;
		n = n->next;
		cout << "Deleting Node ";
		cout << pointer->data << endl;
		free(pointer);
	}
	cout << "Deleting Node ";
	cout << n->data << endl;
	free(n);
}