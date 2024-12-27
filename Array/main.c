#include <stdio.h>
#include "header.h"

int main() {
    ArrayADT arr;
    initArray(&arr, MAX_SIZE);

    int choice, element, index;
    ArrayADT arr2, joinedArray;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Initialize Array with Random Elements\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Update Element\n");
        printf("7. Find Maximum\n");
        printf("8. Find Minimum\n");
        printf("9. Reverse Array\n");
        printf("10. Sort Array\n");
        printf("11. Append Element\n");
        printf("12. Join Two Arrays\n");
        printf("13. Free Array Memory\n");
        printf("14. Exit\n");
        printf("15. Move negative\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of elements to fill: ");
            int num_elements;
            scanf("%d", &num_elements);
            fillArray(&arr, num_elements);
            break;
        case 2:
            display(&arr);
            break;
        case 3:
            printf("Enter element to insert and index: ");
            scanf("%d %d", &element, &index);
            insertEle(&arr, element, index);
            break;
        case 4:
            printf("Enter index to delete: ");
            scanf("%d", &index);
            deleteEle(&arr, index);
            break;
        case 5:
            printf("Enter element to search: ");
            scanf("%d", &element);
            index = searchEle(&arr, element);
            if (index != -1)
                printf("Element %d found at index %d\n", element, index);
            else
                printf("Element not found.\n");
            break;
        case 6:
            printf("Enter index and new element: ");
            scanf("%d %d", &index, &element);
            updateEle(&arr, index, element);
            break;
        case 7:
            printf("Maximum Element: %d\n", findMAX(&arr));
            break;
        case 8:
            printf("Minimum Element: %d\n", findMIN(&arr));
            break;
        case 9:
            reverse(&arr);
            break;
        case 10:
            sortarray(&arr);
            break;
        case 11:
            printf("Enter element to append: ");
            scanf("%d", &element);
            appendEle(&arr, element);
            break;
        case 12:
            printf("Initializing and filling second array.\n");
            initArray(&arr2, 50);
            fillArray(&arr2, arr2.size);
            joinedArray = joinarrays(&arr, &arr2);
            printf("Joined Array:\n");
            display(&joinedArray);
            freeArray(&joinedArray);
            break;
        case 13:
            freeArray(&arr);
            break;
        case 14:
            printf("Exiting...\n");
            freeArray(&arr);
            break;
        case 15:
            mov_neg(&arr);
            display(&arr);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 14);

    return 0;
}
