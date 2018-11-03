#include "stdafx.h"
#include <iostream>
#include "LinkedListOps.h"


using namespace std;

struct Node* head;
struct Node* first;
struct Node* second;
struct Node* third;


void LinkedListTest()
{
	
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node)); 


	head->data = 1;
	head->next = first;
	first->data = 2;
	first->next = second;
	second->data = 3;
	second->next = third; 
	third->data = 4;
	third->next = NULL; 

	SimpleReverse(head); 
	printlist( third);
	getchar();
	//freeAllfromfirst(head);
	

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


void SimpleReverse(struct Node* root)
{
	/*const char* test = "Helloworld";
	static int duplicates = 0; 
	for (signed int i = 0; i < strlen(test); i++)
	{
		for (signed int j = i+1 ; j < strlen(test); j++)
		{
			if (test[i] == test[j])
			{
				++duplicates; 
				cout << duplicates << "   " << test[j] << endl;
				
			}
		}
	}*/

	/*getchar();
	exit(0);*/

	Node* new_root = 0;
	while (root) {
		Node* next = root->next;
		root->next = new_root; 
		new_root = root;
		root = next; 
	}


}


void ReverseLinkedList(struct Node* p)
{
	struct Node* previous  = NULL; 
	struct Node* newp = NULL; 
	struct Node* topnode = NULL;

	while ( p->next != NULL)
	{
		newp = p; 

		while ( newp != NULL && newp->next != NULL)
		{
			previous = newp; 
			newp = newp->next;
		}
		if (newp->next == NULL)
		{
			if (topnode != NULL)
			{
				topnode->next = newp;
			}
			else
			{
				topnode = newp;
			}
			newp->next = p;
			previous->next = NULL;
		}
		

	}

}

