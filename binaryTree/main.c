#include <stdio.h>
#include "header.h"

int main()
{
    Node *root = NULL;

    printf("Create the tree:\n");
    root = insertNode(root);

    printf("\nInorder traversal of the binary tree:\n");
    inorder(root);

    printf("\nNumber of leaf nodes: %d\n", rcount_leaf(root));
    printf("Number of non-leaf nodes: %d\n", rcount_nonleaf(root));
    printf("Height (recursive): %d\n", Height(root));

    return 0;
}
