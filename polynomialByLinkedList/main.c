#include <stdio.h>
#include "header.h"

int main()
{
    Node *p1 = NULL;
    Node *p2 = NULL;

    p1 = insertTerm(p1, 2, 3);
    p1 = insertTerm(p1, -6, 1);
    p1 = insertTerm(p1, 2, 2);

    p2 = insertTerm(p2, 1, 3);
    p2 = insertTerm(p2, 3, 1);
    p2 = insertTerm(p2, 9, 2);

    printf("Polynomial 1st is: ");
    display(p1);

    printf("Polynomial 2nd is: ");
    display(p2);

    Node *sum = addPoly(p1, p2);
    printf("Sum of Polynomials are:  ");
    display(sum);

    Node *sub = subpoly(p1, p2);
    printf("Subtraction of Polynomials are :");
    display(sub);

    return 0;
}
