#include <stdio.h>
#include "header.h"

int main()
{
    int vertices = 7;
    Graph g;
    initGraph(&g, vertices);
    addEdge(&g, 5, 4);
    addEdge(&g, 5, 3);
    addEdge(&g, 4, 2);
    addEdge(&g, 4, 6);
    addEdge(&g, 3, 6);
    addEdge(&g, 6, 1);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    displayGraph(&g);
    BFS(g, 5);
    DFS(g, 5);
    freeGraph(&g);
    return 0;
}
