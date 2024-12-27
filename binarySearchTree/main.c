#include <stdio.h>
#include "header.h"

int main() {
    struct Node *temp;

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    temp = search(30);
    if (temp != NULL) {
        printf("Element %d found\n", temp->data);
    } else {
        printf("Element not found\n");
    }
    Delete(root, 30);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Leaf nodes count: %d\n", count_leaf(root));
    printf("Non-leaf nodes count: %d\n", count_nonleaf(root));
    printf("Height of tree: %d\n", NHeight(root));

    return 0;
}
