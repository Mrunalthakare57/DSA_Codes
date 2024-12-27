#include "header.h"

// Stack function implementations

void sinit(Stack* s, int size) {
    s->size = size;
    s->top = -1;
    s->data = (int*)malloc(size * sizeof(int));
}

int isFull(Stack* s) {
    return s->top == s->size - 1;
}

int s_isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack* s) {
    if (s_isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// Graph function implementations

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

void DFS(Graph* g, int startVertex) {
    Stack s;
    sinit(&s, g->numVertices);

    int* visited = (int*)calloc(g->numVertices, sizeof(int));

    push(&s, startVertex);
    printf("DFS: ");

    while (!s_isEmpty(&s)) {
        int k = pop(&s);

        if (!visited[k]) {
            printf("%d ", k);
            visited[k] = 1;
        }

        Node* temp = g->adjLists[k];
        while (temp) {
            if (!visited[temp->dest]) {
                push(&s, temp->dest);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(s.data);
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(g->adjLists);
}
