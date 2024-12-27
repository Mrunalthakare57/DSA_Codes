#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Create a queue
Queue *createQueue(int tsize)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->ptr = (int *)malloc(sizeof(int) * tsize);
    q->front = 0;
    q->rear = -1;
    q->tsize = tsize;
    q->usize = 0;

    return q;
}

// Check if the queue is empty
bool isEmptyQueue(Queue *q)
{
    return q->usize == 0;
}

// Check if the queue is full
bool isFullQueue(Queue *q)
{
    return q->usize >= q->tsize;
}

// Enqueue an element into the queue
void enqueue(Queue *q, int data)
{
    if (isFullQueue(q))
    {
        printf("Queue is full, cannot enqueue !!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->tsize;
    q->ptr[q->rear] = data;
    q->usize++;
}

// Dequeue an element from the queue
int dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty, cannot dequeue !!\n");
        return -1;
    }
    int data = q->ptr[q->front];
    q->front = (q->front + 1) % q->tsize;
    q->usize--;

    return data;
}

// Get the front element of the queue
int front(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty !!\n");
        return -1;
    }
    return q->ptr[q->front];
}

// Create a stack using two queues
Stack *createStack(int tsize)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->q1 = createQueue(tsize);
    st->q2 = createQueue(tsize);

    return st;
}

// Push an element to the stack (enqueue to q1)
void push(Stack *st, int data)
{
    enqueue(st->q1, data);
}

// Pop an element from the stack (dequeue from q1)
int pop(Stack *st)
{
    if (isEmptyQueue(st->q1))
    {
        printf("Stack is empty, cannot pop !!\n");
        return -1;
    }

    while (st->q1->usize > 1)
    {
        enqueue(st->q2, dequeue(st->q1));
    }
    // The last element in q1 is the top of the stack
    int poppedValue = dequeue(st->q1);

    // Swap q1 and q2
    Queue *temp = st->q1;
    st->q1 = st->q2;
    st->q2 = temp;

    return poppedValue;
}

// Get the top element of the stack (dequeue from q1 and put back)
int top(Stack *st)
{
    if (isEmptyQueue(st->q1))
    {
        printf("Stack is empty !!\n");
        return -1;
    }

    while (st->q1->usize > 1)
    {
        enqueue(st->q2, dequeue(st->q1));
    }

    // The last element in q1 is the top of the stack
    int topValue = dequeue(st->q1);

    // Put the top element back in q2
    enqueue(st->q2, topValue);

    // Swap q1 and q2
    Queue *temp = st->q1;
    st->q1 = st->q2;
    st->q2 = temp;

    return topValue;
}

// Check if the stack is empty
bool isEmptyStack(Stack *st)
{
    return isEmptyQueue(st->q1);
}
