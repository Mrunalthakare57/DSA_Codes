#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isalnum() function
#include "header.h"

// Function to return precedence of operators
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

// Initialize the stack
void init(Stack *s)
{
    s->top = -1;
}

// Check if the stack is empty
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
void push(Stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

// Pop an element from the stack
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// Peek the top element of the stack
char peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->data[s->top];
}

// Function to reverse the string
void reverse(char *exp)
{
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infix_to_prefix(char *s, char *ans)
{
    Stack st;
    init(&st);
    int i = 0, k = 0;

    // Reverse the infix expression
    reverse(s);

    // Modify parentheses (swap '(' with ')')
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    i = 0;
    while (i < strlen(s))
    {
        // If the character is an operand, add it to the output
        if (isalnum(s[i]))
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
            while (!isEmpty(&st) && prec(s[i]) < prec(peek(&st)))
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

    ans[k] = '\0'; // Null-terminate the prefix expression

    // Reverse the result to get the final prefix expression
    reverse(ans);
}
