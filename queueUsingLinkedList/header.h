typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peek(Queue* q);
void display(Queue *q);
