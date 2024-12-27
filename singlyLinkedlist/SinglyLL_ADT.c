#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initList()
{
    return NULL;
}

Node *createNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode)
        return NULL; // Return NULL if memory allocation fails
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertatbeg(Node **head, int data)
{
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    newnode->next = *head;
    *head = newnode;
}

void insertatend(Node **head, int data)
{
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertafter(Node *prevnode, int data)
{
    if (prevnode == NULL)
    {
        printf("Previous node cannot be null\n");
        return;
    }
    Node *newnode = createNode(data);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}

void insertatposition(Node *head, int position, int data)
{
    if (head == NULL || position < 1)
    {
        printf("Invalid position or LIST IS EMPTY\n");
        return;
    }
    Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position %d is out of bounds\n", position);
        return;
    }
    Node *newnode = createNode(data);
    if (!newnode)
        return;
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteatbeg(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatend(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteatpositon(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 0)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position is out of bounds\n");
        return;
    }
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int searchEle(Node *head, int data)
{
    int position = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}
void updateele(Node *head, int position, int newdata)
{
    Node *temp = head;
    int currentpos = 0;
    while (temp != NULL)
    {
        if (currentpos == position)
        {
            temp->data = newdata;
            return;
        }
        temp = temp->next;
        currentpos++;
    }
    printf("Position is out of range!!\n");
}
int length(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int isPalindrome(Node *head)
{
    int len = length(head);
    int *arr = (int *)malloc(len * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation Failed!!");
        return 0;
    }
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    for (int j = 0; j < len / 2; j++)
    {
        if (arr[j] != arr[len - j - 1])
        {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

void removeduplicates(Node *head)
{
    Node *current = head;
    while (current != NULL && current->next != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (current->data == runner->next->data)
            {
                Node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void sortLinkedList(Node **head)
{
    if (*head == NULL)
        return;
    Node *current, *nextnode;
    int swapped;

    do
    {
        swapped = 0;
        current = *head;

        while (current->next != NULL)
        {
            nextnode = current->next;

            if (current->data > nextnode->data)
            {
                int temp = current->data;
                current->data = nextnode->data;
                nextnode->data = temp;
                swapped = 1;
            }
            current = nextnode;
        }
    } while (swapped);
}

int main()
{
    Node *head = initList();

    printf("List before Insertion: ");
    display(head);

    printf("List after Insertion: ");
    insertatend(&head, 50);
    insertatbeg(&head, 40);
    insertatbeg(&head, 20);
    insertatbeg(&head, 80);
    insertatend(&head, 330);
    insertafter(head->next, 30);
    insertatposition(head, 1, 777);
    display(head);

    printf("Deletion at Beginning: ");
    deleteatbeg(&head);
    display(head);

    printf("Deletion at End: ");
    deleteatend(&head);
    display(head);

    printf("Delete at Position: ");
    deleteatpositon(&head, 1);
    display(head);

    int position = searchEle(head, 30);
    if (position != -1)
    {
        printf("Element found at position %d\n", position);
    }
    else
    {
        printf("Element not found!!!\n");
    }

    printf("After Updating Element: ");
    updateele(head, 1, 777);
    display(head);

    printf("Lenght of list:%d\n", length(head));
    if (isPalindrome(head))
    {
        printf("List is Palindrome\n");
    }
    else
    {
        printf("List is not Palindrome\n");
    }

    printf("List after removing duplicates: ");
    removeduplicates(head);
    display(head);
    printf("List after sorting:  ");
    sortLinkedList(&head);
    display(head);

    return 0;
}
