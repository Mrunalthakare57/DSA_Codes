#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

// Structure definitions

typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

typedef struct Stack {
    int size;
    int top;
    int* data;
} Stack;

// Function prototypes

void sinit(Stack* s, int size);
int isFull(Stack* s);
int s_isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
Node* createNode(int dest, int weight);
void initGraph(Graph* g, int vertices);
void addEdge(Graph* g, int src, int dest, int weight);
void removeEdge(Graph* g, int src, int dest);
void displayGraph(Graph* g);
void DFS(Graph* g, int startVertex);
void freeGraph(Graph* g);

#endif // HEADER_H
