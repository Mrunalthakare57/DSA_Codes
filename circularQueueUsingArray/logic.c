#include <stdio.h>
#include "header.h"

void init(CQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CQueue *q) {
    return q->front == -1;
}

int isFull(CQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(CQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Enqueued Value: %d\n", value);
}

int dequeue(CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int del = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued Element: %d\n", del);
    return del;
}

int peek(CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front];
}

void display(CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue is: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX) {
        printf("%d ", q->data[i]);
    }
    printf("%d\n", q->data[q->rear]);
}
