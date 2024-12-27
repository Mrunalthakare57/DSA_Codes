#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CQueue;

void init(CQueue *q);
int isEmpty(CQueue *q);
int isFull(CQueue *q);
void enqueue(CQueue *q, int value);
int dequeue(CQueue *q);
int peek(CQueue *q);
void display(CQueue *q);

