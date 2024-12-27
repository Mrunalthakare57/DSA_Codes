#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    printf("Polynomial 1 is:\n");
    poly *p1 = create(3);
    set(p1, 0, 2, 3);
    set(p1, 1, -6, 1);
    set(p1, 2, 2, 2);
    sort(p1);
    display(p1);

    printf("Polynomial 2 is :\n");
    poly *p2 = create(3);
    set(p2, 0, 1, 3);
    set(p2, 1, 3, 1);
    set(p2, 2, 9, 2);
    sort(p2);
    display(p2);

    printf("Addition of 2 poly :\n");
    poly *p3 = add(p1, p2);
    sort(p3);
    display(p3);

    printf("Subtraction of 2 Poly :\n");
    poly *p4 = sub(p1, p2);
    sort(p4);
    display(p4);

    // Freeing the dynamically allocated memory
    free(p1->t);
    free(p1);
    free(p2->t);
    free(p2);
    free(p3->t);
    free(p3);
    free(p4->t);
    free(p4);

    return 0;
}
