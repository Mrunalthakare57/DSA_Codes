#include <stdio.h>
#include "header.h"

int main() {
    int vertices = 4;

    // Initialize graph structure
    Graph g;
    initGraph(&g, vertices);

    // Add edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);

    printf("Graph before removing an edge:\n");
    displayGraph(&g);

    // Remove an edge
    printf("\nRemoving edge 1-2...\n");
    removeEdge(&g, 1, 2);

    printf("Graph after removing the edge:\n");
    displayGraph(&g);

    // Free the allocated memory
    freeGraph(&g);

    return 0;
}
