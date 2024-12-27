#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to create a new node with the given value
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node *insertNode(Node *root)
{
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    // If -1 is entered, return NULL (no node)
    if (x == -1)
    {
        return NULL;
    }

    // Create a new node using the createNode function
    Node *newNode = createNode(x);

    // Recursively insert lchild and rchild children
    printf("Enter lchild child of %d: ", x);
    newNode->lchild = insertNode(newNode->lchild); // Insert lchild child
    printf("Enter rchild child of %d: ", x);
    newNode->rchild = insertNode(newNode->rchild); // Insert rchild child

    return newNode;
}

// Function to perform inorder traversal of the tree
void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

// Function to count the number of leaf nodes in the tree
int rcount_leaf(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        return 1;
    }
    return rcount_leaf(p->lchild) + rcount_leaf(p->rchild);
}

// Function to count the number of non-leaf nodes in the tree
int rcount_nonleaf(Node *p)
{
    if (p == NULL || (p->lchild == NULL && p->rchild == NULL))
    {
        return 0;
    }
    return 1 + rcount_nonleaf(p->lchild) + rcount_nonleaf(p->rchild);
}

// Function to calculate the height of the tree
int Height(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int x = Height(p->lchild);
    int y = Height(p->rchild);

    return 1 + (x > y ? x : y);
}
