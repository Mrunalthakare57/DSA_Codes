#include <stdio.h>
#include "header.h"

int main()
{
    Node *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);

    printf("Stack after pushing elements: ");
    display(stack);

    printf("Popped Element %d\n", pop(&stack));
    printf("Stack after popping an element: ");
    display(stack);

    printf("Top element (PEEK): %d\n", peek(stack));

    printf("\nSorting the stack...\n");
    sortStack(&stack);
    printf("Stack after sorting: ");
    display(stack);

    printf("\nReversing the stack...\n");
    reverse(&stack);
    printf("Stack after reversing: ");
    display(stack);

    return 0;
}
