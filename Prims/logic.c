#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"


// Initialize graph with given number of vertices
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    g->matrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->matrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->matrix[i][j] = INT_MAX;  // Initialize with infinity
        }
    }
}

// Add an edge between two vertices with the given weight
void addEdge(Graph* g, int u, int v, int weight) {
    g->matrix[u][v] = weight;
    g->matrix[v][u] = weight;  // As the graph is undirected
}

// Prim's algorithm for Minimum Spanning Tree
void prim(Graph* g, int x) {
    int startvertex = x - 1;  // Adjusting to 0-based index

    int d = g->vertices;
    int* near = (int*)calloc(d, sizeof(int));

    for (int i = 0; i < d; i++) {
        near[i] = INT_MAX;  // Initialize near array
    }

    int minwt = INT_MAX, u, v;

    // MST stores the edges of the minimum spanning tree
    int* MST[2];
    MST[0] = (int*)calloc(d - 1, sizeof(int));
    MST[1] = (int*)calloc(d - 1, sizeof(int));

    // Find the first edge with minimum weight
    for (int i = 0; i < d; i++) {
        if (g->matrix[startvertex][i] < minwt) {
            minwt = g->matrix[startvertex][i];
            u = startvertex;
            v = i;
        }
    }

    MST[0][0] = u;
    MST[1][0] = v;
    near[u] = 0;
    near[v] = 0;

    // Update the nearest vertices for each vertex
    for (int i = 0; i < d; i++) {
        if (near[i] != 0) {
            if (g->matrix[i][u] < g->matrix[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Find the MST edges
    int k;
    for (int i = 1; i < d - 1; i++) {
        minwt = INT_MAX;
        for (int j = 0; j < d; j++) {
            if ((near[j] != 0) && (g->matrix[j][near[j]] < minwt)) {
                minwt = g->matrix[j][near[j]];
                k = j;
            }
        }
        MST[0][i] = k;
        MST[1][i] = near[k];
        near[k] = 0;
    }

    // Output the MST edges
    for (int i = 0; i < d - 1; i++) {
        printf("\n%d -> %d", MST[0][i] + 1, MST[1][i] + 1);
    }

    // Free the dynamically allocated memory for MST and near arrays
    free(MST[0]);
    free(MST[1]);
    free(near);
}

// Free the memory allocated for the graph
void freeGraph(Graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
}
