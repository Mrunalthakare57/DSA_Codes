#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    int del = q->data[q->front];
    q->front++;

    // Reset queue if all elements are dequeued
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }

    printf("Dequeued Element: %d\n", del);
    return del;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front];
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue is: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
