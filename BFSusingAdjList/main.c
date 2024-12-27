#include <stdio.h>
#include "header.h"

int main() {
    int vertices = 7;

    // Initialize graph structure
    Graph g;
    initGraph(&g, vertices);

    // Add edges
    addEdge(&g, 0, 1, 1);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 2, 3, 1);
    addEdge(&g, 3, 5, 1);
    addEdge(&g, 4, 1, 1);
    addEdge(&g, 5, 2, 1);
    addEdge(&g, 6, 3, 1);

    printf("Graph:\n");
    displayGraph(&g);

    printf("BFS from vertex 0:\n");
    BFS(&g, 0);

    // Remove an edge
    printf("\nRemoving edge 1-2...\n");
    removeEdge(&g, 1, 2);

    printf("Graph after removing the edge:\n");
    displayGraph(&g);

    return 0;
}
