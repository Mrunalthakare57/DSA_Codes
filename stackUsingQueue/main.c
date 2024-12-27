#include <stdio.h>
#include "header.h"

int main()
{
    Stack *st = createStack(10);

    // Push elements onto the stack
    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);

    printf("Top element: %d\n", top(st));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(st));
    printf("Popped element: %d\n", pop(st));

    printf("Top element: %d\n", top(st));

    push(st, 50);
    printf("Top element: %d\n", top(st));

    // Pop all elements from the stack
    while (!isEmptyStack(st))
    {
        printf("Popped element: %d\n", pop(st));
    }

    return 0;
}
