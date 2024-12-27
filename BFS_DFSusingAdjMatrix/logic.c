#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Queue functions
void qinit(Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->data = (int *)malloc(size * sizeof(int));
}

int isFull(Queue *q)
{
    return q->rear == q->size - 1;
}

int isEmpty(Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->data[++q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->data[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return value;
}

// Stack functions
void sinit(Stack *s, int size)
{
    s->size = size;
    s->top = -1;
    s->data = (int *)malloc(size * sizeof(int));
}

int isFullStack(Stack *s)
{
    return s->top == s->size - 1;
}

int s_isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (isFullStack(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s)
{
    if (s_isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// Graph functions
void initGraph(Graph *g, int vertices)
{
    g->numVertices = vertices;
    g->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        g->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
        {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest)
{
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void removeEdge(Graph *g, int src, int dest)
{
    g->adjMatrix[src][dest] = 0;
    g->adjMatrix[dest][src] = 0;
}

void displayGraph(Graph *g)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
        {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
}

// Graph traversal functions
void BFS(Graph g, int startVertex)
{
    Queue q;
    qinit(&q, g.numVertices);
    int *visited = calloc(g.numVertices, sizeof(int));
    visited[startVertex] = 1;
    printf("BFS: %d ", startVertex);
    enqueue(&q, startVertex);
    while (!isEmpty(&q))
    {
        int c = dequeue(&q);
        for (int i = 0; i < g.numVertices; i++)
        {
            if (g.adjMatrix[c][i] == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
    free(visited);
    free(q.data);
}

void DFS(Graph g, int startVertex)
{
    Stack s;
    sinit(&s, g.numVertices);
    int *visited = calloc(g.numVertices, sizeof(int));
    printf("DFS: ");
    push(&s, startVertex);
    while (!s_isEmpty(&s))
    {
        int k = pop(&s);
        if (visited[k] == 0)
        {
            printf("%d ", k);
            visited[k] = 1;
        }
        for (int i = 0; i < g.numVertices; i++)
        {
            if (g.adjMatrix[k][i] == 1 && visited[i] == 0)
            {
                push(&s, i);
            }
        }
    }
    printf("\n");
    free(visited);
    free(s.data);
}
