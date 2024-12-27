#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

int main() {
    // Define a graph and initialize it with the number of vertices
    Graph g;
    int vertices = 5;
    initGraph(&g, vertices);

    // Add edges to the graph with weights
    addEdge(&g, 0, 1, 2);
    addEdge(&g, 0, 3, 6);
    addEdge(&g, 1, 2, 3);
    addEdge(&g, 1, 3, 8);
    addEdge(&g, 1, 4, 5);
    addEdge(&g, 2, 4, 7);
    addEdge(&g, 3, 4, 9);

    // Print the MST starting from vertex 1 (1-based index)
    printf("Prim's MST starting from vertex 1:\n");
    prim(&g, 1);

    // Free the graph memory
    freeGraph(&g);

    return 0;
}
