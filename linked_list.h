//
// Created by Kirsten S. on 2019-07-14.
//
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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
	Node *node = createNode(rand() | rand() << 15);
	*head = node;
	length--;
	
	while (length > 0)
	{
		node->next = createNode(rand() | rand() << 15);
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
    //int i=1;
    //int nVal = 0;
    while(head != NULL)
    {
    	//nVal = head->data;
        printf("%d -> ", head->data);
        //i++;

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

Node* QuickSortPtr(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *pivot = TailNode(head); // O(n)
    Node *left = NULL, *right = NULL;
}


Node* Partition(Node *start, Node *end, Node **tmpStart, Node **tmpEnd)
{
    Node *pivot = end, *prev = NULL, *curr = start, *tail = pivot;

    while(curr != pivot)
    {
        if(curr->data < pivot->data)
        {
            if(*tmpStart == NULL)
                *tmpStart = curr;
            prev = curr;
            curr = curr->next;
        } else
        {
            if (prev)
                prev->next = curr->next;
            SwapByPtr(&curr, &tail);
        }
    }
    if(*tmpStart == NULL)
        *tmpStart = pivot;
    *tmpEnd = tail;
    return pivot;
}

Node* QuickSortData(Node* head, Node* end) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = NULL, *newEnd = NULL;
    Node *pivot = Partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while(tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = QuickSortData(newHead, tmp);
        tmp = TailNode(newHead);
        tmp->next = pivot;
    }
    pivot->next = QuickSortData(pivot->next, newEnd);
    return newHead;
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

#ifdef _WIN32
#include <windows.h>

/*
 * Do not forget to initialize the clock so the timer would work.
 */
double frequency;
void initClock()
{
	LARGE_INTEGER _frequency;
	QueryPerformanceFrequency(&_frequency);
	frequency = (double)_frequency.QuadPart;
}

double millis()
{
	LARGE_INTEGER _count;
	QueryPerformanceCounter(&_count);
	double count = (double)_count.QuadPart;
	return count / frequency * 1000.0;
}

#else

/* clock() is found to have lower precision than the time APIs provided by operating systems */

void initClock() {}

double millis()
{
	return (double)clock() / CLOCKS_PER_SEC * 1000.0;
}

#endif
