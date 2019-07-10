#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int length;
    int* values;
} array;

array createArray(int length) {
    array a;
    a.length = length;
    a.values = (int*) malloc(sizeof(int) * length);
    return a;
}

void deleteArray(array a) {
    free(a.values);
}

void randomizeArray(array a) {
    int i;

    srand((unsigned int)time(NULL));
    for (i = 0; i < a.length; i++)
        a.values[i] = rand() | rand() << 15;
}

void printArray(array a) {
    int i;
    printf("[");
    for (i = 0; i < a.length; i++)
        printf(" %d ", a.values[i]);
    printf("]\n");
}

/* QUICKSORT ALGORITHM */

/* Quicksort important notes:
 * Correct position in final, sorted array
 * Items to the left are smaller
 * Items to the right are smaller
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(array a, int low, int high) {
    int i, pivot = a.values[high];
    int pIndex = low;
    for (i = low; i < high; i++) {
        if (a.values[i] <= pivot) {
            swap(&a.values[i], &a.values[pIndex]);
            pIndex++;
        }
    }
    swap(&a.values[pIndex], &a.values[high]);
    return pIndex;
}

void quicksort(array *a, int low, int high) {
    int pIndex;
    if (low < high) {
        pIndex = partition(*a, low, high);
        quicksort(a, low, pIndex - 1);
        quicksort(a, pIndex + 1, high);
    }
}

/* SELECTION SORT ALGORITHM */
void selectionsort(array a) {
    int i, j, min;
    for (i = 0; i < a.length - 1; i++) {
        min = i;
        for (j = i + 1; j < a.length; j++) {
        	if (a.values[j] < a.values[min])
        		min = j;
        }
        swap(&a.values[i], &a.values[min]);
    }
}

/* BUBBLE SORT ALGORITHM */
void bubblesort(array a) {
	int nTemp;

	for (i = 0; i < a.length; i++) {	          // will repeat checking every element up to the array's size to compare all elements to one another
        for (j = 0; j < a.length; j++) {          // compares an element (j) to the one beside it (j+1),						a switch will occur only if the element at j is greater than the element at j+1
        	if (a.values[j] > a.values[j + 1] && j + 1 < nSize) //	only compare elements (j's value) until nSize - 1
        		swap(&a.values[j], &a.values[j + 1]);
        }
	}
}

int main() {
    printf("\nBefore Bubble Sort:\n");
    array a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Bubble Sort:\n");
    bubblesort(a);
    printArray(a);
    deleteArray(a);

    printf("\nBefore Selection Sort:\n");
    array a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Selection Sort:\n");
    selectionsort(a);
    printArray(a);
    deleteArray(a);

    printf("\nBefore Quicksort:\n");
    array a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Quicksort:\n");
    quicksort(&a, 0, a.length-1);
    printArray(a);
    deleteArray(a);

    return 0;
}
