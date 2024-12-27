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

    int resultLinear = linearSearch(&arr, searchKey);

    if (resultLinear != -1)
    {
        printf("Key %d found at index %d using linear search\n", searchKey, resultLinear);
    }
    else
    {
        printf("Key %d is not present in the array\n", searchKey);
    }

       return 0;
}
