typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function prototypes
void initGraph(Graph *g, int vertices);
void addEdge(Graph *g, int src, int dest, int weight);
void displayGraph(Graph *g);
int findMin(int *dist, int *visited, int vertices);
void Dijkstra(Graph *g, int src);
void freeGraph(Graph *g);
