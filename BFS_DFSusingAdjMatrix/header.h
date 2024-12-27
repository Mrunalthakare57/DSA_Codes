typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

typedef struct Stack
{
    int *data;
    int top, size;
} Stack;

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *data;
} Queue;

// Function prototypes for Queue operations
void qinit(Queue *q, int size);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);

// Function prototypes for Stack operations
void sinit(Stack *s, int size);
int isFullStack(Stack *s);
int s_isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);

// Function prototypes for Graph operations
void initGraph(Graph *g, int vertices);
void addEdge(Graph *g, int src, int dest);
void removeEdge(Graph *g, int src, int dest);
void displayGraph(Graph *g);
void freeGraph(Graph *g);

// Function prototypes for Graph traversal
void BFS(Graph g, int startVertex);
void DFS(Graph g, int startVertex);
