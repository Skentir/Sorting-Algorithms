#include <stdio.h>
#include "linked_list.h"

// BEGIN MERGE SORT 1



// END MERGE SORT 1

// BEGIN MERGE SORT 2

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

// END MERGE SORT 2

int main() {
    printf("grease is the best musical fite me\n");
    int length = 5;
    Node *head = NULL;
    createList(&head, length);
    display(head);
    printf("\nQuicksort by swapping data: \n");
    Node *tmp = QuickSortData(head, TailNode(head));
    display(tmp);
    printf("\nQuicksort by swapping pointers: \n");
    return 0;
}

/*
 * Linked List Basic Operations: Parlante, N. (2001) Linked List Basics  Stanford.edu
 * Swap: Flowers, B. H., Flowers, S. B. H., & Flowers, F. and F. R. B. H. (2000). An Introduction to Numerical Methods in C++. Oxford University Press.
 * QSort: https://github.com/Aufuray/quicksort-on-linkedlist/blob/master/codefile.c
 * */
