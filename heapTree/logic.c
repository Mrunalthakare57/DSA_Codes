#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the heap property
void heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && A[left] > A[largest])
    {
        largest = left;
    }

    if (right <= n && A[right] > A[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

// Function to initialize the heap from an array
void initHeap(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(A, n, i);
    }
}

// Function to insert an element into the heap
void insertHeap(int A[], int n)
{
    int temp = A[n];
    int i = n;

    while (i > 1 && A[i] > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

// Function to delete the root element (max value) from the heap
int deleteHeap(int A[], int n)
{
    int val = A[1];
    A[1] = A[n];
    A[n] = val;
    int i = 1;
    int j = 2 * i;

    while (j <= n - 1)
    {
        if (j + 1 <= n && A[j + 1] > A[j])
        {
            j = j + 1;
        }

        if (A[i] < A[j])
        {
            swap(&A[i], &A[j]);
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }

    return val;
}

void heapSort(int A[], int n)
{
    

    initHeap(A, n);

    for (int i = n; i > 1; i--)
    {
        swap(&A[1], &A[i]);

        heapify(A, i - 1, 1);
    }
}
