#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

// Function to initialize the graph with the specified number of vertices
void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    g->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        g->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = INT_MAX; // Initialize with no edges
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph *g, int src, int dest, int weight) {
    g->adjMatrix[src][dest] = weight;
    // Uncomment the next line for an undirected graph
    // g->adjMatrix[dest][src] = weight;
}

// Function to display the adjacency matrix of the graph
void displayGraph(Graph *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == INT_MAX)
                printf("INF "); // Represent no edge as INF
            else
                printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the vertex with the minimum distance
int findMin(int *dist, int *visited, int vertices) {
    int min = INT_MAX, u = -1;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

// Dijkstra's algorithm to find the shortest path from a source vertex
void Dijkstra(Graph *g, int src) {
    int vertices = g->numVertices;
    int dist[vertices];    // Array to store shortest distances
    int visited[vertices]; // Array to mark visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0; // Distance to source is 0

    // Process all vertices
    for (int i = 0; i < vertices - 1; i++) {
        // Pick the minimum distance vertex
        int u = findMin(dist, visited, vertices);
        if (u == -1) // No more reachable vertices
            break;
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && g->adjMatrix[u][v] != INT_MAX &&
                dist[u] + g->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjMatrix[u][v];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

// Function to free memory allocated for the graph
void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
}
