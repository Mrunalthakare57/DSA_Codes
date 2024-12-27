typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
int isEmpty(Node *top);
void push(Node **top, int data);
int pop(Node **top);
int peek(Node *top);
void display(Node *top);
void sortStack(Node **original);
void reverse(Node **top);
