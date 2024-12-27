#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Queue functions
void qinit(Queue* q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->data = (int*)malloc(size * sizeof(int));
}

int isFull(Queue* q) {
    return q->rear == q->size - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->data[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->data[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1; 
    return value;
}

// Graph functions
Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    g->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
    }
}

void addEdge(Graph* g, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void removeEdge(Graph* g, int src, int dest) {
    Node* temp = g->adjLists[src];
    Node* prev = NULL;

    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            g->adjLists[src] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }

    temp = g->adjLists[dest];
    prev = NULL;

    while (temp != NULL && temp->dest != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            g->adjLists[dest] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

void displayGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->adjLists[i];
        printf("Vertex %d |", i);
        while (temp) {
            printf(" -> %d (weight: %d)", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// BFS function
void BFS(Graph* g, int startVertex) {
    Queue q;
    qinit(&q, g->numVertices);

    int* visited = (int*)calloc(g->numVertices, sizeof(int));
    enqueue(&q, startVertex);
    visited[startVertex] = 1;

    printf("BFS: ");
    while (!isEmpty(&q)) {
        int c = dequeue(&q);
        printf("%d ", c);

        Node* temp = g->adjLists[c];
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(q.data);
}
