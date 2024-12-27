#include <stdio.h>
#include "header.h"

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This will not be added as the queue is full

    display(&q);
    dequeue(&q);
    display(&q);

    printf("Peek element: %d\n", peek(&q));
    display(&q);

    return 0;
}
