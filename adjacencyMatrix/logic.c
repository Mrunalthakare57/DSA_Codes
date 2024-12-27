#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to initialize a graph with the specified number of vertices
void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;

    g->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge between src and dest
void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to remove an edge between src and dest
void removeEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 0;
    g->adjMatrix[dest][src] = 0; // For undirected graph
}

// Function to display the graph as an adjacency matrix
void displayGraph(Graph *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
}
