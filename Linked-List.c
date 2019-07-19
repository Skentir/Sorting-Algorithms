#include <stdio.h>
#include "linked_list.h"

// BEGIN QUICK SORT

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

// END QUICK SORT

// BEGIN MERGE SORT

Node *middleNode(Node *a, Node *b)
{
	Node *m = a, *n = a;
	while (m != b && m->next != b)
	{
		m = m->next;
		if (m != NULL) m = m->next;
		n = n->next;
	}
	return n;
}

void append(Node **curr, Node **head, Node **tail)
{
    if (head == NULL)
	{
        *curr = NULL;
		return;
	}
    else if (*head == NULL)
    {
		*head = *tail = *curr;
    }
    else
    {
        (*tail)->next = *curr;
		*tail = (*tail)->next;
    }
	
	*curr = (*curr)->next;
}

void merge(Node **head, Node *mid, Node **tail)
{
	Node *front1 = *head;
	Node *front2 = mid;
	Node *stop1 = mid;
	Node *stop2 = (*tail)->next;
	
	Node *front = NULL, *back = NULL;
	while (front1 != stop1 && front2 != stop2) {
		if (front1->data <= front2->data) {
			append(&front1, &front, &back);
		} else {
			append(&front2, &front, &back);
		}
	}
	
	while (front1 != stop1) {
		append(&front1, &front, &back);
	}
	while (front2 != stop2) {
		append(&front2, &front, &back);
	}
	
	back->next = stop2;
	
	*head = front;
	*tail = back;
}

void mergesort_do(Node **head, Node **tail)
{
	if (*head != *tail)
	{
		Node *mid = middleNode(*head, *tail);
		mergesort_do(head, &mid);
		mergesort_do(&(mid->next), tail);
		merge(head, mid->next, tail);
	}
}

void mergesort(Node **head)
{
	Node *tail = TailNode(*head);
	mergesort_do(head, &tail);
}

// END MERGE SORT
// START BUBBLE SORT
void bubbleSortList(Node **head)
{
	Node *prevNode = NULL;
	Node *currNode = *head;
	Node *nextNode = (*head)->next;
	Node *temp, *oldHead; 
	int bVal = 0;
	
	while(bVal == 0)
	{
		prevNode = NULL;
		currNode = (*head);
		nextNode = (*head)->next;
		bVal = 1;	
		while(nextNode != NULL)
		{
			if(currNode->data > nextNode->data)
			{
				temp = nextNode->next;
				nextNode->next = currNode;
				currNode->next = temp;
				
				if(prevNode != NULL)
				{
					prevNode->next = nextNode;	
				}
				else
				{
					*head = nextNode;
				}
				
				prevNode = nextNode;
				nextNode = currNode->next;
				
				bVal = 0;
				
				
			}
			else
			{
				prevNode = currNode;
				
				currNode = currNode->next;
				nextNode = nextNode->next;
			}
		}
	}
}
//END BUBBLE SORT
int main() {
    printf("grease is the best musical fite me\n");
    int i, length;
    Node *head = NULL, *tmp;
	double start, time;
	
	initRandom();
	initClock();
	
	length = 2;
	printf("Testing quicksort:\n");
	for (i = 0; i < 23; i++) {
		printf("Create list of %d nodes:\n", length);
		createList(&head, length);
		//printf("Before sorting:\n");
		//display(head);
		start = millis();
		head = QuickSortData(head, TailNode(head));
		time = millis() - start;
		//printf("After sorting:\n");
		//display(tmp);
		if (!validateList(head, length)) {
			printf("Bad list!\n");
			display(head);
			//return 1;
		} else {
			printf("Good!\n");
			printf("Time taken is %lf ms\n", time);
		}
		deleteList(&head);
		length *= 2;
	}
	
	length = 2;
	printf("Testing mergesort:\n");
	for (i = 0; i < 23; i++) {
		printf("Create list of %d nodes:\n", length);
		createList(&head, length);
		//printf("Before sorting:\n");
		//display(head);
		start = millis();
		mergesort(&head);
		time = millis() - start;
		//printf("After sorting:\n");
		//display(tmp);
		if (!validateList(head, length)) {
			printf("Bad list!\n");
			display(head);
			//return 1;
		} else {
			printf("Good!\n");
			printf("Time taken is %lf ms\n", time);
		}
		deleteList(&head);
		length *= 2;
	}
	
    return 0;
}

/*
 * Linked List Basic Operations: Parlante, N. (2001) Linked List Basics  Stanford.edu
 * Swap: Flowers, B. H., Flowers, S. B. H., & Flowers, F. and F. R. B. H. (2000). An Introduction to Numerical Methods in C++. Oxford University Press.
 * QSort: https://github.com/Aufuray/quicksort-on-linkedlist/blob/master/codefile.c
 * */
