#include <stdio.h>
#include "header.h"

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This will be enqueued if the queue size allows

    display(&q);

    dequeue(&q);
    display(&q);

    printf("Peek: %d\n", peek(&q));

    return 0;
}
