#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// Initialize the array
void initArray(Array *arr, int totalSize)
{
    arr->totalSize = totalSize;
    arr->usedSize = 0;
    arr->elements = (int *)malloc(sizeof(int) * totalSize);
}

void insertElements(Array *arr)
{
    printf("Enter the elements in the array: \n");
    for (int i = 0; i < arr->totalSize; i++)
    {
        scanf("%d", &arr->elements[i]);
        arr->usedSize++;
    }
}

int linearSearch(Array *arr, int key)
{
    for (int i = 0; i < arr->usedSize; i++)
    {
        if (arr->elements[i] == key)
        {
            return i; // If key found, return index
        }
    }
    return -1; // If key not found, return -1
}

void display(Array *arr)
{
    if (arr->usedSize == 0)
    {
        printf("Array is empty\n");
        return;
    }
    else
    {
        for (int i = 0; i < arr->usedSize; i++)
        {
            printf("%d ", arr->elements[i]);
        }
        printf("\n");
    }
}
