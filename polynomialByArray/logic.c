#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Create a new polynomial with given number of terms
poly *create(int num) {
    poly *p = (poly *)malloc(sizeof(poly));
    p->t = (term *)malloc(num * sizeof(term));
    p->num = num;
    return p;
}

// Set the coefficient and exponent for a term at a given index
void set(poly *p, int i, int c, int e) {
    if (i >= 0 && i < p->num) {
        p->t[i].coef = c;
        p->t[i].expo = e;
    } else {
        printf("Out of bounds\n");
    }
}

// Sort the polynomial terms by exponent in descending order
void sort(poly *p) {
    for (int i = 0; i < p->num - 1; i++) {
        for (int j = 0; j < p->num - i - 1; j++) {
            if (p->t[j].expo < p->t[j + 1].expo) {
                term temp = p->t[j];
                p->t[j] = p->t[j + 1];
                p->t[j + 1] = temp;
            }
        }
    }
}

// Display the polynomial in a human-readable format
void display(poly *p) {
    printf("Given Polynomial is :");
    for (int i = 0; i < p->num; i++) {
        if (i > 0) {
            if (p->t[i].coef >= 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        }
        printf("%d", abs(p->t[i].coef));

        if (p->t[i].expo > 0) {
            printf("x^%d", p->t[i].expo);
        }
    }
    printf("\n");
}

// Add two polynomials and return the resulting polynomial
poly *add(poly *p1, poly *p2) {
    poly *p3 = create(p1->num + p2->num);
    int i = 0, j = 0, k = 0;

    while (i < p1->num && j < p2->num) {
        if (p1->t[i].expo > p2->t[j].expo) {
            p3->t[k++] = p1->t[i++];
        } else if (p1->t[i].expo < p2->t[j].expo) {
            p3->t[k++] = p2->t[j++];
        } else {
            p3->t[k].expo = p1->t[i].expo;
            p3->t[k++].coef = p1->t[i++].coef + p2->t[j++].coef;
        }
    }

    while (i < p1->num) {
        p3->t[k++] = p1->t[i++];
    }

    while (j < p2->num) {
        p3->t[k++] = p2->t[j++];
    }

    p3->num = k;
    return p3;
}

// Subtract the second polynomial from the first polynomial and return the result
poly *sub(poly *p1, poly *p2) {
    poly *p3 = create(p1->num + p2->num);
    int i = 0, j = 0, k = 0;

    while (i < p1->num && j < p2->num) {
        if (p1->t[i].expo > p2->t[j].expo) {
            p3->t[k++] = p1->t[i++];
        } else if (p1->t[i].expo < p2->t[j].expo) {
            p3->t[k++] = p2->t[j++];
        } else {
            p3->t[k].expo = p1->t[i].expo;
            p3->t[k++].coef = p1->t[i++].coef - p2->t[j++].coef;
        }
    }

    while (i < p1->num) {
        p3->t[k++] = p1->t[i++];
    }

    while (j < p2->num) {
        p3->t[k++] = p2->t[j++];
    }

    p3->num = k;
    return p3;
}
