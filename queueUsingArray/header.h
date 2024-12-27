#define MAX 5

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);
void display(Queue *q);
