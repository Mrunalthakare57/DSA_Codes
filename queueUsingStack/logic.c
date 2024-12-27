#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Create a stack
Stack* createStack(int tsize){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->ptr = (int*)malloc(sizeof(int) * tsize);
    st->tsize = tsize;
    st->top = -1;
    return st;
}

// Check if the stack is empty
bool isEmptyStack(Stack *st){
    return st->top == -1;
}

// Check if the stack is full
bool isFullStack(Stack *st){
    return st->top >= st->tsize-1;
}

// Push an element to the stack
void push(Stack *st, int data){
    if(isFullStack(st)){
        printf("Stack overflow !!\n");
        return;
    }
    st->ptr[++st->top] = data;
}

// Pop an element from the stack
int pop(Stack *st){
    if(isEmptyStack(st)){
        printf("Stack underflow !!\n");
        return -1;
    }   
    return st->ptr[st->top--];
}

// Peek the top element of the stack
int peek(Stack *st){
    if(isEmptyStack(st)){
        printf("Nothing to peek, stack underflow !!\n");
        return -1;
    }
    return st->ptr[st->top];
}

// Create a queue using two stacks
Queue* createQueue(int tsize){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1 = createStack(tsize);
    q->s2 = createStack(tsize);
    return q;
}

// Enqueue an element into the queue
void enqueue(Queue *q, int data){
    push(q->s1, data);
    printf("Enqueued %d\n", data);
}

// Dequeue an element from the queue
int dequeue(Queue *q){
    if(isEmptyStack(q->s1) && isEmptyStack(q->s2)){
        printf("Queue is empty !!\n");
        return -1;
    }

    if(isEmptyStack(q->s2)){
        while(!isEmptyStack(q->s1)){
            push(q->s2, pop(q->s1));
        }
    }

    int dequeued = pop(q->s2);
    printf("Dequeued : %d\n", dequeued);
    return dequeued;
}

// Check if the queue is empty
bool isEmptyQueue(Queue *q){
    return isEmptyStack(q->s1) && isEmptyStack(q->s2);
}

// Get the front element of the queue
int front(Queue *q){
    if(isEmptyQueue(q)){
        printf("Queue is empty, nothing at front !!\n");
        return -1;
    }

    if(isEmptyStack(q->s2)){
        while(!isEmptyStack(q->s1)){
            push(q->s2, pop(q->s1));
        }
    }

    return peek(q->s2);
}
