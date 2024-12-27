#include <stdio.h>
#include <string.h>
#include "header.h"

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Push an element to the stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

// Pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// Peek the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->data[s->top];
}

// Function to convert infix to postfix
void infix_to_postfix(char *s, char *ans)
{
    Stack st;
    init(&st);
    int i = 0, k = 0;

    while (i < strlen(s))
    {
        // If the character is an operand, add it to the output
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans[k++] = s[i];
        }
        // If the character is '(', push it to the stack
        else if (s[i] == '(')
        {
            push(&st, s[i]);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (s[i] == ')')
        {
            while (!isEmpty(&st) && peek(&st) != '(')
            {
                ans[k++] = pop(&st);
            }
            pop(&st); // Pop '('
        }
        // An operator is encountered
        else
        {
            while (!isEmpty(&st) && prec(s[i]) <= prec(peek(&st)))
            {
                ans[k++] = pop(&st);
            }
            push(&st, s[i]); // Push current operator to stack
        }
        i++;
    }

    // Pop all the operators from the stack
    while (!isEmpty(&st))
    {
        ans[k++] = pop(&st);
    }

    ans[k] = '\0'; // Null-terminate the postfix expression
}
