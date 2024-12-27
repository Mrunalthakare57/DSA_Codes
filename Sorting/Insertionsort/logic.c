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

// Insertion Sort
void insertionSort(Array *array)
{
    if (array->usedSize == 0)
    {
        printf("Array is empty, nothing to sort!!\n");
        return;
    }
    for (int i = 1; i < array->usedSize; i++)
    {
        int key = array->elements[i];
        int j = i - 1;
        while (j >= 0 && array->elements[j] > key)
        {
            array->elements[j + 1] = array->elements[j];
            j--;
        }
        array->elements[j + 1] = key;
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
