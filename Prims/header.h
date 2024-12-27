typedef struct Graph {
    int vertices;
    int** matrix;  // Adjacency matrix
} Graph;

// Function prototypes
void prim(Graph* g, int x);
void initGraph(Graph* g, int vertices);
void addEdge(Graph* g, int u, int v, int weight);
void freeGraph(Graph* g);
