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
// Quick Sort Helper
int partition(Array *array, int low, int high)
{
    int pivot = array->elements[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array->elements[j] <= pivot)
        {
            i++;
            int temp = array->elements[i];
            array->elements[i] = array->elements[j];
            array->elements[j] = temp;
        }
    }
    int temp = array->elements[i + 1];
    array->elements[i + 1] = array->elements[high];
    array->elements[high] = temp;
    return (i + 1);
}

void quickSortHelper(Array *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSortHelper(array, low, pi - 1);
        quickSortHelper(array, pi + 1, high);
    }
}
// Quick Sort
void quickSort(Array *array)
{
    if (array->usedSize == 0)
    {
        printf("Array is empty, nothing to sort!!\n");
        return;
    }
    quickSortHelper(array, 0, array->usedSize - 1);
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
