#include <stdio.h>
#include "header.h"

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

    printf("Length of list: %d\n", length(head));
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
