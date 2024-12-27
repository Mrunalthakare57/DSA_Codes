#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node *create(int coef, int expo)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->coef = coef;
    newnode->expo = expo;
    newnode->next = NULL;
    return newnode;
}

Node *insertTerm(Node *head, int coef, int expo)
{
    Node *newnode = create(coef, expo);
    if (head == NULL || expo > head->expo)
    {
        newnode->next = head;
        return newnode;
    }
    Node *temp = head;
    while (temp->next != NULL && temp->next->expo >= expo)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->coef);
        if (temp->expo != 0)
        {
            printf("x^%d", temp->expo);
        }
        if (temp->next != NULL && temp->next->coef >= 0)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node *addPoly(Node *p1, Node *p2)
{
    Node *result = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            result = insertTerm(result, p1->coef, p1->expo);
            p1 = p1->next;
        }
        else if (p1->expo < p2->expo)
        {
            result = insertTerm(result, p2->coef, p2->expo);
            p2 = p2->next;
        }
        else
        {
            result = insertTerm(result, p1->coef + p2->coef, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        result = insertTerm(result, p1->coef, p1->expo);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        result = insertTerm(result, p2->coef, p2->expo);
        p2 = p2->next;
    }
    return result;
}

Node *subpoly(Node *p1, Node *p2)
{
    Node *result = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            result = insertTerm(result, p1->coef, p1->expo);
            p1 = p1->next;
        }
        else if (p1->expo < p2->expo)
        {
            result = insertTerm(result, p2->coef, p2->expo);
            p2 = p2->next;
        }
        else
        {
            result = insertTerm(result, p1->coef - p2->coef, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        result = insertTerm(result, p1->coef, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        result = insertTerm(result, p2->coef, p2->expo);
        p2 = p2->next;
    }
    return result;
}
