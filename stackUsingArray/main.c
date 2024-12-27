#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    Stack s;
    int choice, value;

    initStack(&s);

    while (1) {
        // Display the menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            
            case 2:
                // Pop operation
                value = pop(&s);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            
            case 3:
                // Peek operation
                value = peek(&s);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            
            case 4:
                // Display stack elements
                display(&s);
                break;
            
            case 5:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
