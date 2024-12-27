#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} CQueue;

// Function to initialize the queue
void initQueue(CQueue *q)
{
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(CQueue *q)
{
    return q->front == NULL;
}

// Function to enqueue (add) an element to the queue
void enqueue(CQueue *q, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (isEmpty(q))
    {
        // When queue is empty, both front and rear point to the new node
        q->front = q->rear = newnode;
        newnode->next = q->front; // Point the new node's next to itself (making it circular)
    }
    else
    {
        // Insert new node at the rear and make the queue circular
        q->rear->next = newnode;
        q->rear = newnode;
        q->rear->next = q->front; // Rear points back to front to make it circular
    }
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int del;
    Node *temp = q->front;

    if (q->front == q->rear)
    {
        // Only one element in the queue
        del = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else
    {
        // More than one element
        del = q->front->data;
        q->front = q->front->next;
        q->rear->next = q->front; // Rear's next should still point to the new front
        free(temp);
    }
    printf("Dequeued: %d\n", del);
    return del;
}

// Function to get the front element of the queue
int peek(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Function to display the elements of the queue
void display(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    Node *temp = q->front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front); // Loop until we circle back to the front
    printf("\n");
}

// Main function to test the circular queue
int main()
{
    CQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    display(&q);

    printf("Peek: %d\n", peek(&q));
    display(&q);

    return 0;
}
