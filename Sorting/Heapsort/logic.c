#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// Initialize the array
void initArray(Array *array, int totalSize)
{
    array->totalSize = totalSize;
    array->usedSize = 0;
    array->elements = (int *)malloc(sizeof(int) * totalSize);
}

// Insert elements into the array
void insertElements(Array *array)
{
    printf("Enter the elements in the array:\n");
    for (int i = 0; i < array->totalSize; i++)
    {
        scanf("%d", &array->elements[i]);
        array->usedSize++;
    }
}

// Heap Sort Helper: Heapify function
void heapify(Array *array, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array->elements[left] > array->elements[largest])
    {
        largest = left;
    }

    if (right < n && array->elements[right] > array->elements[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = array->elements[i];
        array->elements[i] = array->elements[largest];
        array->elements[largest] = temp;
        heapify(array, n, largest);
    }
}

// Heap Sort
void heapSort(Array *array)
{
    if (array->usedSize == 0)
    {
        printf("Array is empty, nothing to sort!!\n");
        return;
    }
    int n = array->usedSize;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = array->elements[0];
        array->elements[0] = array->elements[i];
        array->elements[i] = temp;
        heapify(array, i, 0);
    }
}

// Display the array
void display(Array *array)
{
    if (array->usedSize == 0)
    {
        printf("Array is empty\n");
        return;
    }
    for (int i = 0; i < array->usedSize; i++)
    {
        printf("%d ", array->elements[i]);
    }
    printf("\n");
}
