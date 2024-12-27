typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} CQueue;

// Function declarations
void initQueue(CQueue *q);
int isEmpty(CQueue *q);
void enqueue(CQueue *q, int value);
int dequeue(CQueue *q);
int peek(CQueue *q);
void display(CQueue *q);
