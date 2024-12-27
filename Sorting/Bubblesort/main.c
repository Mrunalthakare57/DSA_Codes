#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    Array arr;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    initArray(&arr, size);
    insertElements(&arr);
    if (arr.usedSize == 0)
    {
        printf("No elements to sort.\n");
        return 0;
    }
    display(&arr);
    bubbleSort(&arr);
    printf("Sorted array: ");
    display(&arr);
    free(arr.elements);
    return 0;
}