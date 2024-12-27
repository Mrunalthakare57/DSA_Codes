#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node *initList() {
    return NULL;
}

Node *createNode(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory allocation Failed!\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertatbeg(Node **head, int data) {
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    newnode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newnode;
    }
    *head = newnode;
}

void insertatend(Node **head, int data) {
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertafter(Node *prevnode, int data) {
    if (prevnode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    newnode->prev = prevnode;
    if (newnode->next != NULL) {
        newnode->next->prev = newnode;
    }
}

void insertatposition(Node **head, int position, int data) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or list is empty\n");
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position %d is out of bounds\n", position);
        return;
    }
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void deleteatbeg(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteatend(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteNode(Node **head, Node *delnode) {
    if (*head == NULL || delnode == NULL) {
        printf("Invalid deletion\n");
        return;
    }
    if (*head == delnode) {
        *head = delnode->next;
    }
    if (delnode->next != NULL) {
        delnode->next->prev = delnode->prev;
    }
    if (delnode->prev != NULL) {
        delnode->prev->next = delnode->next;
    }
    free(delnode);
}

void display(Node *head) {
    Node *temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int searchEle(Node *head, int data) {
    int position = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

int updatele(Node *head, int position, int element) {
    int currentpos = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (currentpos == position) {
            temp->data = element;
            return 1;
        }
        temp = temp->next;
        currentpos++;
    }
    printf("Position is out of bounds\n");
    return 0;
}

int length(Node *head) {
    int len = 0;
    Node *temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

int ispalindrome(Node *head) {
    int len = length(head);
    int *arr = (int *)malloc(len * sizeof(int));
    if (!arr) {
        printf("MEMORY ALLOCATION FAILED\n");
        return 0;
    }
    Node *temp = head;
    int i = 0;
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    for (int j = 0; j < len / 2; j++) {
        if (arr[j] != arr[len - j - 1]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

void removeduplicates(Node *head) {
    Node *current = head;
    while (current != NULL && current->next != NULL) {
        Node *runner = current;
        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                Node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void sortedLink(Node **head) {
    if (*head == NULL)
        return;
    Node *current, *nextnode;
    int swapped;
    do {
        swapped = 0;
        current = *head;
        while (current->next != NULL) {
            nextnode = current->next;
            if (current->data > nextnode->data) {
                int temp = current->data;
                current->data = nextnode->data;
                nextnode->data = temp;
                swapped = 1;
            }
            current = nextnode;
        }
    } while (swapped);
}
