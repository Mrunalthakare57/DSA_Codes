// logic.c

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Node *initList() {
    return NULL;
}

Node *createNode(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = newnode;
    return newnode;
}

void insertatbeg(Node **head, int data) {
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newnode->next = *head;
        temp->next = newnode;
        *head = newnode;
    }
}

void insertatend(Node **head, int data) {
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;
    }
}

void insertafter(Node *prevnode, int data) {
    if (prevnode == NULL) {
        printf("Previous node cannot be null\n");
        return;
    }
    Node *newnode = createNode(data);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}

void inseratposition(Node **head, int position, int data) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    Node *newnode = createNode(data);
    if (!newnode)
        return;

    if (position == 1) {
        if (*head == NULL) {
            *head = newnode;
            newnode->next = *head;
        } else {
            Node *temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            newnode->next = *head;
            *head = newnode;
            temp->next = *head;
        }
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp->next == *head && position > 1) {
        printf("Position %d is out of bounds\n", position);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteatbeg(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == *head) {
        free(*head);
        *head = NULL;
        return;
    } else {
        Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

void deleteatend(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == *head) {
        free(*head);
        *head = NULL;
        return;
    } else {
        while (temp->next->next != *head) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = *head;
    }
}

void deleteatposition(Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        deleteatbeg(head);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp->next == *head || temp->next == NULL) {
        printf("Position is out of bounds\n");
        return;
    }
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int searchEle(Node *head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int position = 0;
    Node *temp = head;
    do {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    return -1;  // Element not found
}

int updateEle(Node *head, int position, int newdata) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int currentpos = 0;
    Node *temp = head;
    do {
        if (currentpos == position) {
            temp->data = newdata;
            return 0;
        }
        temp = temp->next;
        currentpos++;
    } while (temp != head);

    printf("Position is out of range\n");
    return -1;
}

int length(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return 0;
    }
    int len = 0;
    Node *temp = head;
    do {
        len++;
        temp = temp->next;
    } while (temp != head);
    return len;
}

int isPalindrome(Node *head) {
    int len = length(head);
    int *arr = (int *)malloc(len * sizeof(int));
    if (!arr) {
        printf("Memory allocation Failed\n");
        return 0;
    }

    Node *temp = head;
    int i = 0;
    do {
        arr[i++] = temp->data;
        temp = temp->next;
    } while (temp != head);

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
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *current = head;
    do {
        Node *runner = current;
        while (runner->next != head) {
            if (current->data == runner->next->data) {
                Node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current != head);
}

void sortLinkedList(Node **head) {
    if (*head == NULL)
        return;

    Node *current, *nextnode;
    int swapped;

    do {
        swapped = 0;
        current = *head;

        do {
            nextnode = current->next;

            if (current->data > nextnode->data) {
                int temp = current->data;
                current->data = nextnode->data;
                nextnode->data = temp;
                swapped = 1;
            }
            current = nextnode;
        } while (current->next != *head);

    } while (swapped);
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
