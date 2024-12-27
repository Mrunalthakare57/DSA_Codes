#include <stdio.h>
#include "header.h"

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;

    // Initial heap (before insertions)
    printf("Initial heap (before insertions):\n");
    initHeap(H, 7);
    for (i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    // Inserting elements into the heap
    printf("Inserting elements into heap:\n");
    int newElement = 50;
    printf("Inserting %d\n", newElement);
    H[8] = newElement;
    insertHeap(H, 8);

    for (i = 1; i <= 8; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    // Deleting root element (max value)
    printf("Deleting root element (max value):\n");
    deleteHeap(H, 8);
    for (i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    // Heap Sort in action
    printf("Heap Sort in action:\n");
    heapSort(H, 7);
    for (i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
