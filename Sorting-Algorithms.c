/* hello world */

#include <stdint.h>
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

    for (i = 0; i < a.length; i++)
        a.values[i] = rand() % 500;
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

/**
     * Hoare partition scheme.
     * The original partition scheme described by C.A.R. Hoare uses two indices that start at
     * the ends of the array being partitioned, then move toward each other, until they detect
     * an inversion
     *
     * Hoare's scheme is more efficient than Lomuto's partition scheme because it does three
     * times fewer swaps on average, and it creates efficient partitions even when all values
     * are equal.
     *  Source: https://github.com/ljp215/algorithm/blob/master/src/main/java/com/zane/algorithm/QuickSort.java
     */
void quicksort2(array *a, int low, int high)
{
    if (low < high)
    {
        int indx = low+high/2;
        int pivot = a->values[indx];
        /* Pivot is swapped with last */
        a->values[indx] = a->values[high];
        a->values[high] = pivot;

        int i = low -1;
        int j = high;

        do {
            do{i++;} while (a->values[i] < pivot);
            /*Cannot be out of bounds as a[high] contains the pivot, so it will stop advancing afterwards*/
            do{j--;} while((a->values[j]> pivot) && (j >low));
            if(i < j) {
                swap(&a->values[i], &a->values[j]);
            }
        } while (i < j);

        a->values[high] = a->values[i];
        a->values[i] = pivot;

        quicksort2(a, low, i-1);
        quicksort2(a, i+1, high);

    }
}
/**
     * Lomuto partition scheme.
     * This scheme is attributed to Nico Lomuto and popularized by Bentley in his book
     * Programming Pearls
     * Source: https://github.com/ljp215/algorithm/blob/master/src/main/java/com/zane/algorithm/QuickSort.java
 */

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

void quicksort1(array *a, int low, int high) {
    int pIndex;
    if (low < high) {
        pIndex = partition(*a, low, high);
        quicksort1(a, low, pIndex - 1);
        quicksort1(a, pIndex + 1, high);
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
    int i, j;

	for (i = 0; i < a.length; i++) {	          // will repeat checking every element up to the array's size to compare all elements to one another
        for (j = 0; j < a.length; j++) {          // compares an element (j) to the one beside it (j+1),						a switch will occur only if the element at j is greater than the element at j+1
        	if (a.values[j] > a.values[j + 1] && j + 1 < a.length) //	only compare elements (j's value) until nSize - 1
        		swap(&a.values[j], &a.values[j + 1]);
        }
	}
}

/* MERGE SORT ALGORITHM */
/*
void merge(array a, int p, int q, int r) {
	int i, j, k;

	int n1 = q - p + 1;
	int n2 = r - q;
	array L = createArray(n1+1);
	array R = createArray(n2+1);
	for (i = 0; i < n1; i++)
		L.values[i] = a.values[p + i];
	for (j = 0; j < n2; j++)
		R.values[j] = a.values[q + j + 1];

	L.values[n1] = INT32_MAX;
	R.values[n2] = INT32_MAX;

	i = 0;
	j = 0;
	for (k = p; k <= r; k++) {
		if (L.values[i] <= R.values[j]) {
			a.values[k] = L.values[i];
			i++;
		} else {
			a.values[k] = R.values[j];
			j++;
		}
	}

	deleteArray(L);
	deleteArray(R);
}

void mergesort_do(array a, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergesort_do(a, p, q);
		mergesort_do(a, q + 1, r);
		merge(a, p, q, r);
	}
}

void mergesort(array a) {
	mergesort_do(a, 0, a.length - 1);
}
*/
void merge(array a, int p, int q, int r) {
	int i, j, k;
	
	// a b c d e
	// p = 0, q = 2, r = 4
	
	int n1 = q - p + 1;
	int n2 = r - q;
	array L = createArray(n1);
	array R = createArray(n2);
	for (i = 0; i < n1; i++)
		L.values[i] = a.values[p + i];
	for (j = 0; j < n2; j++)
		R.values[j] = a.values[q + j + 1];
	/*
	for (k = p; k <= r; k++) {
		if (L.values[i] <= R.values[j]) {
			a.values[k] = L.values[i];
			i++;
		} else {
			a.values[k] = R.values[j];
			j++;
		}
	}
	*/
	i = 0;
	j = 0;
	while (i < n1 && j < n2) {
		if (L.values[i] <= R.values[j]) {
			a.values[k] = L.values[i];
			i++;
		} else {
			a.values[k] = R.values[j];
			j++;
		}
	}
	while (i < n1) {
		a.values[k] = L.values[i];
		i++;
	}
	while (j < n2) {
		a.values[k] = R.values[j];
		j++;
	}

	deleteArray(L);
	deleteArray(R);
}

void mergesort_do(array a, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergesort_do(a, p, q);
		mergesort_do(a, q + 1, r);
		merge(a, p, q, r);
	}
}

void mergesort(array a) {
	mergesort_do(a, 0, a.length - 1);
}

void insertionSort(array a)
{
	int nTemp;//		initalizes value at i = 0
	
	int arrSize = a.length;
	
	
	int i, j;
	
	for(i = 0; i < arrSize; i++)//		compare against all values in the array
	{
		for(j = i; j > 0 ; j--)//		sorts the array into two parts	~> sorted||unsorted
		{
			 if(a.values[j-1] > a.values[j])//if the curr value in the unsorted partition is bigger than the one below it (both sorted
			 {//				and unsorted), initiate a swap	
			 	swap(&a.values[j], &a.values[j-1]);
			 }
		}
	}
}
int main() {
    array a;
	double start, time;

    srand((unsigned int)time(NULL));

    printf("\nBefore Bubble Sort:\n");
    a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Bubble Sort:\n");
	start = millis();
    bubblesort(a);
	time = millis() - start;
    printArray(a);
    deleteArray(a);

    printf("\nBefore Selection Sort:\n");
    a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Selection Sort:\n");
    selectionsort(a);
    printArray(a);
    deleteArray(a);

    printf("\nBefore Quicksort 1:\n");
    a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Quicksort 1:\n");
    quicksort1(&a, 0, a.length-1);
    printArray(a);
    deleteArray(a);

    printf("\nBefore Quicksort 2:\n");
    a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Quicksort 2:\n");
    quicksort2(&a, 0, a.length-1);
    printArray(a);
    deleteArray(a);
	
    printf("\nBefore Insertion Sort:\n");
    a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Insertion Sort:\n");
    insertionSort(a);
    printArray(a);
    deleteArray(a);
    
    printf("\nBefore Mergesort:\n");
    a = createArray(5);
    randomizeArray(a);
    printArray(a);
    printf("After Mergesort:\n");
    mergesort(a);
    printArray(a);
    deleteArray(a);

    return 0;
}
