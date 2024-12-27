#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to initialize the queue
void initQueue(CQueue *q)
{
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(CQueue *q)
{
    return q->front == NULL;
}

// Function to enqueue (add) an element to the queue
void enqueue(CQueue *q, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newnode;
        newnode->next = q->front; // Point the new node's next to itself (making it circular)
    }
    else
    {
        q->rear->next = newnode;
        q->rear = newnode;
        q->rear->next = q->front;
    }
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int del;
    Node *temp = q->front;

    if (q->front == q->rear)
    {
        del = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else
    {
        del = q->front->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    printf("Dequeued: %d\n", del);
    return del;
}

// Function to get the front element of the queue
int peek(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Function to display the elements of the queue
void display(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node *temp = q->front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}
