#include <stdio.h>
#include "header.h"

int main() {
    int vertices = 4;

    // Initialize the graph
    Graph g;
    initGraph(&g, vertices);

    // Add edges to the graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);

    // Display the graph
    displayGraph(&g);

    // Free the allocated memory for the graph
    freeGraph(&g);

    return 0;
}
