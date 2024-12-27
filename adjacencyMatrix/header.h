typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

void initGraph(Graph *g, int vertices);
void addEdge(Graph *g, int src, int dest);
void removeEdge(Graph *g, int src, int dest);
void displayGraph(Graph *g);
void freeGraph(Graph *g);
