#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void initArray(ArrayADT *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    if (!arr->data) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    arr->size = size;
    arr->length = 0;
}

void fillArray(ArrayADT *arr, int num_elements) {
    if (num_elements > arr->size) {
        printf("Number of elements exceeds array size!\n");
        return;
    }
    for (int i = arr->length; i < num_elements; i++) {
        arr->data[i] = rand() % 100 + 1;
    }
    arr->length = num_elements;
}

void display(ArrayADT *arr) {
    if (arr->length == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < arr->length; i++) {
        printf("%d  ", arr->data[i]);
    }
    printf("\n");
}

void insertEle(ArrayADT *arr, int element, int index) {
    if (arr->length >= arr->size) {
        printf("Array is Full\n");
        return;
    }
    if (index < 0 || index > arr->length) {
        printf("Invalid Index\n");
        return;
    }
    for (int i = arr->length; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = element;
    arr->length++;
}

void deleteEle(ArrayADT *arr, int index) {
    if (arr->length == 0) {
        printf("Array is empty.\n");
        return;
    }
    if (index < 0 || index >= arr->length) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < arr->length - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
    printf("Element deleted.\n");
}

int searchEle(ArrayADT *arr, int element) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->data[i] == element) {
            return i;
        }
    }
    return -1;
}

void updateEle(ArrayADT *arr, int index, int newEle) {
    if (index < 0 || index >= arr->length) {
        printf("Invalid index!\n");
        return;
    }
    arr->data[index] = newEle;
    printf("Element updated.\n");
}

int findMAX(ArrayADT *arr) {
    int max = arr->data[0];
    for (int i = 1; i < arr->length; i++) {
        if (max < arr->data[i]) {
            max = arr->data[i];
        }
    }
    return max;
}

int findMIN(ArrayADT *arr) {
    int min = arr->data[0];
    for (int i = 1; i < arr->length; i++) {
        if (min > arr->data[i]) {
            min = arr->data[i];
        }
    }
    return min;
}

void reverse(ArrayADT *arr) {
    int temp;
    for (int i = 0; i < arr->length / 2; i++) {
        temp = arr->data[i];
        arr->data[i] = arr->data[arr->length - i - 1];
        arr->data[arr->length - i - 1] = temp;
    }
    printf("Array reversed.\n");
}

void sortarray(ArrayADT *arr) {
    int temp, min;
    for (int i = 0; i < arr->length; i++) {
        min = i;
        for (int j = i + 1; j < arr->length; j++) {
            if (arr->data[min] > arr->data[j]) {
                min = j;
            }
        }
        temp = arr->data[min];
        arr->data[min] = arr->data[i];
        arr->data[i] = temp;
    }
    printf("Array sorted.\n");
}

void appendEle(ArrayADT *arr, int element) {
    if (arr->length == arr->size) {
        printf("Array is full.\n");
        return;
    }
    arr->data[arr->length++] = element;
    printf("Element appended.\n");
}

ArrayADT joinarrays(ArrayADT *arr1, ArrayADT *arr2) {
    ArrayADT joined;
    initArray(&joined, arr1->length + arr2->length);

    for (int i = 0; i < arr1->length; i++) {
        appendEle(&joined, arr1->data[i]);
    }

    for (int i = 0; i < arr2->length; i++) {
        appendEle(&joined, arr2->data[i]);
    }
    printf("Arrays joined.\n");
    return joined;
}

void freeArray(ArrayADT *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->length = 0;
    printf("Array memory freed.\n");
}

void mov_neg(ArrayADT *arr) {
    int left = 0, right = arr->length - 1;

    while (left <= right) {
        if (arr->data[left] < 0) {
            left++;
        } else if (arr->data[right] >= 0) {
            right--;
        } else {
            int temp = arr->data[left];
            arr->data[left] = arr->data[right];
            arr->data[right] = temp;
            left++;
            right--;
        }
    }
    printf("Array re-arranged with negatives on the left and positives on the right.\n");
}
