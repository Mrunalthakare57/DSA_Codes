#include <stdio.h>
#include "header.h"

int main()
{
    char infix[] = "(A+B)*(C+D)";
    char result[MAX];

    infix_to_postfix(infix, result);
    printf("Postfix is: %s\n", result);

    return 0;
}
