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

// Bubble Sort
void bubbleSort(Array *array)
{
    if (array->usedSize == 0)
    {
        printf("Array is empty, nothing to sort!!\n");
        return;
    }
    for (int i = 0; i < array->usedSize; i++)
    {
        for (int j = 0; j < array->usedSize - i - 1; j++)
        {
            if (array->elements[j] > array->elements[j + 1])
            {
                int temp = array->elements[j];
                array->elements[j] = array->elements[j + 1];
                array->elements[j + 1] = temp;
            }
        }
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
