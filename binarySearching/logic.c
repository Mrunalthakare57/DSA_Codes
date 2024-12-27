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


int binarySearch(Array *arr, int key)
{
    int left = 0, right = arr->usedSize - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr->elements[mid] == key)
        {
            return mid; // If key found, return index
        }
        else if (arr->elements[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // If key not found, return -1
}

void sort(Array *arr)
{
    if (arr->usedSize == 0)
    {
        printf("Array is empty, nothing to sort!!\n");
        return;
    }
    for (int i = 0; i < arr->usedSize; i++)
    {
        for (int j = 0; j < arr->usedSize - i - 1; j++)
        {
            if (arr->elements[j] > arr->elements[j + 1])
            {
                int temp = arr->elements[j];
                arr->elements[j] = arr->elements[j + 1];
                arr->elements[j + 1] = temp;
            }
        }
    }
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
