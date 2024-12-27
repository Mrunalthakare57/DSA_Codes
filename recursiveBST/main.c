#include <stdio.h>
#include "header.h"

int main()
{
    Node *temp;

    // Inserting nodes into the tree
    root = Rinsert(root, 10);
    Rinsert(root, 5);
    Rinsert(root, 20);
    Rinsert(root, 8);
    Rinsert(root, 30);

    // In-order traversal
    printf("BST After Insertion traversal:\n");
    inorder(root);
    printf("\n");

    // Deleting an element
    int deleteElement = 20;
    printf("Deleting element: %d\n", deleteElement);
    Delete(root, deleteElement);

    // Searching for an element
    temp = Rsearch(root, 10);
    if (temp != NULL)
    {
        printf("Element %d found\n", temp->data);
    }
    else
    {
        printf("Element not found\n");
    }

    // In-order traversal after deletion
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    // Count leaf and non-leaf nodes
    printf("Number of leaf nodes: %d\n", rcount_leaf(root));
    printf("Number of non-leaf nodes: %d\n", rcount_nonleaf(root));
    printf("Height (recursive): %d\n", Height(root));

    return 0;
}
