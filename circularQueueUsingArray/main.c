#include <stdio.h>
#include "header.h"

int main() {
    CQueue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);
    dequeue(&q);
    display(&q);

    printf("Peek Element: %d\n", peek(&q));
    return 0;
}
