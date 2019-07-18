//
// Created by Kirsten S. on 2019-07-14.
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "utility.h"

typedef struct node {
    int data;
    struct node* next;
} Node;

Node *createNode(int value)
{
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = value;
	node->next = NULL;
	return node;
}

void createList(Node **head, int length)
{
	Node *node = createNode(random());
	*head = node;
	length--;
	
	while (length > 0)
	{
		node->next = createNode(random());
		node = node->next;
		length--;
	}
}
/* Returns the number of nodes in the list
 * Head pointer copied to local variable curr and iterates the list
 * Stop when we encounter a NULL pointer
 * Advance pointer if not yet at end of the list*/
int ListLength(Node* head)
{
    int count = 0;
    Node* curr;
    
    for(curr = head; curr != NULL; curr = curr->next)
        count++;
        
    return count;
};

/* Returns the pointer to the last node */
Node* TailNode(Node *curr)
{
    for(; curr->next != NULL; curr= curr->next);
    return curr;
}

/* New data/node is added at the head end.
 * Disadvantage: Elements will appear in reverse order that they are added
 * Advantage: Short and fast
 */
Node* AddToHead(int data)
{
 Node* head = NULL;
 //int i;
 /*insert for loop to move all nodes via Push() */
    return  head;
}

void display(Node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
/* Very first node is added to the head pointer
 * All following nodes are inserted after using a tail pointer
 * Case 1: Adds a node at head ptr
 * Case 2: Adds a node at tail ptr
 * Disadvantage: Adding a case 1 is bit unsatisfying*/
/*
Node* AddToTail(int data)
{
    Node* head = NULL;
    Node* tail;
    if (GetHead() == NULL)
    {
        Push(head, data);
        tail = head;
    } else {
        Push(tail->next, data);
        tail =  tail->next;
    }
    return head;
}
*/

/* Exchanges data stored in linked list */
void SwapByData(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

/* Exchanges data stored in linked list */
void SwapByPtr(Node* (*cur), Node* (*tail))
{
     Node *tmp = (*cur)->next;
    (*cur)->next = NULL;
    (*tail)->next = *cur;
    *tail = *cur;
    *cur = tmp;

}

/*
 * Checks if the linked list is sorted (in ascending order) and contains the
 * right number of nodes ( == count)
 */
int validateList(Node *head, int count)
{
	int value = head->data;
	int counter = 1;
	head = head->next;
	while (head != NULL)
	{
		if (value > head->data)
			return 0;
		value = head->data;
		head = head->next;
		counter++;
	}
	
	return count == counter;
}

/*
 * Deletes all the nodes in the list.
 */
void deleteList(Node **node)
{
	while (*node != NULL)
	{
		Node *next = (*node)->next;
		free(*node);
		*node = next;
	}
	
	*node = NULL;
}
