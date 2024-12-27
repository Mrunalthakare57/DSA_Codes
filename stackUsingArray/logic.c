#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    } else {
        s->top++;
        s->data[s->top] = value;
    }
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->data[s->top--];
    }
}

// Peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

// Display the stack elements
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
        printf("\n");
    }
}
