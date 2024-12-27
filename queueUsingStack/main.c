#include <stdio.h>
#include "header.h"

int main() {
    Queue* q = createQueue(5);

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Print the front element of the queue
    printf("Front element: %d\n", front(q));

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);

    // Enqueue more elements into the queue
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    // Print the front element of the queue again
    printf("Front element: %d\n", front(q));

    // Dequeue all elements from the queue
    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    return 0;
}
