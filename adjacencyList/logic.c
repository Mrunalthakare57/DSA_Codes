#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to create a new adjacency list node
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph with the specified number of vertices
void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;

    // Allocate memory for the adjacency lists
    g->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
    }
}

// Function to add an edge to the graph (undirected graph)
void addEdge(Graph* g, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    // Add edge from dest to src (if undirected)
    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

// Function to remove an edge from the graph
void removeEdge(Graph* g, int src, int dest) {
    // Remove edge from src to dest
    Node* temp = g->adjLists[src];
    Node* prev = NULL;

    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            // The edge to be removed is the first node
            g->adjLists[src] = temp->next;
        } else {
            // The edge is somewhere in the middle or end
            prev->next = temp->next;
        }
        free(temp); // Free the memory allocated for the node
    }

    // Remove edge from dest to src (if undirected)
    temp = g->adjLists[dest];
    prev = NULL;

    while (temp != NULL && temp->dest != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            // The edge to be removed is the first node
            g->adjLists[dest] = temp->next;
        } else {
            // The edge is somewhere in the middle or end
            prev->next = temp->next;
        }
        free(temp); // Free the memory allocated for the node
    }
}

// Function to display the adjacency list of each vertex
void displayGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->adjLists[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(g->adjLists);
}
