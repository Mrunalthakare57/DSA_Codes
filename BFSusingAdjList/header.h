typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

typedef struct Queue {
    int size;
    int front;
    int rear;
    int* data;
} Queue;

// Function declarations
void qinit(Queue* q, int size);
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

Node* createNode(int dest, int weight);
void initGraph(Graph* g, int vertices);
void addEdge(Graph* g, int src, int dest, int weight);
void removeEdge(Graph* g, int src, int dest);
void displayGraph(Graph* g);
void BFS(Graph* g, int startVertex);
