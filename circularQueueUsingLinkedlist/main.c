#include <stdio.h>
#include "header.h"

int main()
{
    CQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    display(&q);

    printf("Peek: %d\n", peek(&q));
    display(&q);

    return 0;
}
