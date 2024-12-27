typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function prototypes
Node* createNode(int dest);
void initGraph(Graph* g, int vertices);
void addEdge(Graph* g, int src, int dest);
void removeEdge(Graph* g, int src, int dest);
void displayGraph(Graph* g);
void freeGraph(Graph* g);
