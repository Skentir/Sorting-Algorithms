#include <stdio.h>
#include "linked_list.h"
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
