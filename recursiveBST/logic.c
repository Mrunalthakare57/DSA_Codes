#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Initialize root node to NULL
Node *root = NULL;

// Function to insert a node recursively
Node *Rinsert(Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}

// Function to search for a node with the given key
Node *Rsearch(Node *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (key == t->data)
    {
        return t;
    }
    else if (key < t->data)
    {
        return Rsearch(t->lchild, key);
    }
    else
    {
        return Rsearch(t->rchild, key);
    }
}

// Recursive function to count leaf nodes
int rcount_leaf(Node *p)
{
    if (p == NULL)
        return 0;

    // If the node is a leaf
    if (p->lchild == NULL && p->rchild == NULL)
        return 1;

    return rcount_leaf(p->lchild) + rcount_leaf(p->rchild);
}

// Recursive function to count non-leaf nodes
int rcount_nonleaf(Node *p)
{
    if (p == NULL || (p->lchild == NULL && p->rchild == NULL))
        return 0;

    return 1 + rcount_nonleaf(p->lchild) + rcount_nonleaf(p->rchild);
}

// Recursive function to calculate height
int Height(Node *p)
{
    if (p == NULL)
        return 0;

    int left_height = Height(p->lchild);
    int right_height = Height(p->rchild);

    return 1 + (left_height > right_height ? left_height : right_height);
}

// Function to find the in-order predecessor
Node *InPre(Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

// Function to find the in-order successor
Node *Insucc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

// Function to delete a node with the given key
Node *Delete(Node *p, int key)
{
    Node *q;
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

// Function to do inorder traversal of the tree
void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
