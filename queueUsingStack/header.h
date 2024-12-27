#include <stdbool.h>

typedef struct Stack {
    int *ptr;
    int top;
    int tsize;
} Stack;

typedef struct Queue {
    Stack *s1; 
    Stack *s2;
} Queue;

Stack* createStack(int tsize);
bool isEmptyStack(Stack *st);
bool isFullStack(Stack *st);
void push(Stack *st, int data);
int pop(Stack *st);
int peek(Stack *st);

Queue* createQueue(int tsize);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
bool isEmptyQueue(Queue *q);
int front(Queue *q);

