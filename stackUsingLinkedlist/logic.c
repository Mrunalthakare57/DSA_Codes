#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to create a new node
Node *createNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode)
    {
        printf("Memory allocation Failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to check if the stack is empty
int isEmpty(Node *top)
{
    return top == NULL;
}

void push(Node **top, int data)
{
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    newnode->next = *top;
    *top = newnode;
}

int pop(Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peek(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}

void display(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty\n");
        return;
    }
    Node *temp = top;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortStack(Node **original)
{
    Node *temp = NULL; // Temporary stack

    while (!isEmpty(*original))
    {
        // Step 1: Pop from the original stack
        int current = pop(original);

        // Step 2: Move elements from temp stack to original stack if they are larger
        while (!isEmpty(temp) && peek(temp) > current)
        {
            push(original, pop(&temp));
        }

        // Step 3: Push the current element into the temp stack
        push(&temp, current);
    }

    // Transfer elements back from temp to original (now sorted)
    while (!isEmpty(temp))
    {
        push(original, pop(&temp));
    }
}

void reverse(Node **top)
{
    Node *prev = NULL;
    Node *current = *top;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;      
    }

    *top = prev; 
}
