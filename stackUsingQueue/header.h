#include <stdbool.h>

// Queue structure
typedef struct QueueNode
{
    int *ptr;
    int front;
    int rear;
    int tsize;
    int usize;
} Queue;

typedef struct Stack
{
    Queue *q1; 
    Queue *q2; 
} Stack;

Queue *createQueue(int tsize);
bool isEmptyQueue(Queue *q);
bool isFullQueue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int front(Queue *q);

Stack *createStack(int tsize);
void push(Stack *st, int data);
int pop(Stack *st);
int top(Stack *st);
bool isEmptyStack(Stack *st);
