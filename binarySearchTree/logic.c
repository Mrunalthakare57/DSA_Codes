#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Initialize root node to NULL
struct Node *root = NULL;

// Function to insert a new node
void insert(int key) {
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key == t->data) {
            return;
        } else if (key < t->data) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }

    // Create the new node after finding the correct position
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    // Attach the new node to the appropriate position (left or right)
    if (key < r->data) {
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

// Inorder traversal
void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

// Preorder traversal
void preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// Postorder traversal
void postorder(struct Node *p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Function to search for a node with the given key
struct Node *search(int key) {
    struct Node *t = root;
    while (t != NULL) {
        if (key == t->data) {
            return t;
        } else if (key < t->data) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return NULL;
}

// Function to calculate height recursively
int Height(struct Node *p) {
    if (p == NULL)
        return 0;

    int left_height = Height(p->lchild);
    int right_height = Height(p->rchild);

    return 1 + (left_height > right_height ? left_height : right_height);
}

// Function to find the in-order predecessor
struct Node *InPre(struct Node *p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

// Function to find the in-order successor
struct Node *Insucc(struct Node *p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// Function to delete a node with the given key
struct Node *Delete(struct Node *p, int key) {
    struct Node *q;
    if (p == NULL)
        return NULL;

    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        // Case 1: Node to be deleted has no children
        if (p->lchild == NULL && p->rchild == NULL) {
            if (p == root) {
                root = NULL;
            }
            free(p);
            return NULL;
        }
        // Case 2: Node to be deleted has two children
        else if (p->lchild != NULL && p->rchild != NULL) {
            // Choose the in-order predecessor (or successor)
            if (Height(p->lchild) > Height(p->rchild)) {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            } else {
                q = Insucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        // Case 3: Node to be deleted has only one child
        else {
            struct Node *child = (p->lchild != NULL) ? p->lchild : p->rchild;
            if (p == root) {
                root = child;
            }
            free(p);
            return child;
        }
    }
    return p;
}

// Function to count leaf nodes iteratively
int count_leaf(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    int leafCount = 0;
    struct Node *stack[100]; // Stack for DFS traversal
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node *node = stack[top--];

        // If the node is a leaf (no children)
        if (node->lchild == NULL && node->rchild == NULL) {
            leafCount++;
        }

        // Push the right child first (if exists)
        if (node->rchild != NULL) {
            stack[++top] = node->rchild;
        }

        // Push the left child (if exists)
        if (node->lchild != NULL) {
            stack[++top] = node->lchild;
        }
    }

    return leafCount;
}

// Function to count non-leaf nodes iteratively
int count_nonleaf(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    int nonLeafCount = 0;
    struct Node *stack[100]; // Stack for DFS traversal
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node *node = stack[top--];

        // If the node is not a leaf (has at least one child)
        if (node->lchild != NULL || node->rchild != NULL) {
            nonLeafCount++;
        }

        // Push the right child first (if exists)
        if (node->rchild != NULL) {
            stack[++top] = node->rchild;
        }

        // Push the left child (if exists)
        if (node->lchild != NULL) {
            stack[++top] = node->lchild;
        }
    }

    return nonLeafCount;
}

// Function to calculate the height iteratively (BFS)
int NHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    int height = 0;
    struct Node *queue[100]; // Queue for BFS traversal
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        height++;

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            struct Node *node = queue[front++];

            if (node->lchild != NULL) {
                queue[rear++] = node->lchild;
            }
            if (node->rchild != NULL) {
                queue[rear++] = node->rchild;
            }
        }
    }

    return height;
}
