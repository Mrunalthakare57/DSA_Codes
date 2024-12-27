#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Array arr;
    int totalSize, searchKey;

    printf("Enter the size of the array: \n");
    scanf("%d", &totalSize);

    initArray(&arr, totalSize);

    insertElements(&arr);

    display(&arr);

    printf("Enter the key to search: ");
    scanf("%d", &searchKey);

        // As binary search works only on sorted arrays, we need to sort the array first
    printf("Before applying binary search, sorting the array: \n");
    sort(&arr);
    display(&arr);

    printf("Applying Binary Search on sorted array: \n");
    int resultBinary = binarySearch(&arr, searchKey);

    if (resultBinary != -1)
    {
        printf("Key %d found at index %d using binary search\n", searchKey, resultBinary);
    }
    else
    {
        printf("Key %d is not present in the array\n", searchKey);
    }

    return 0;
}
