// main.c

#include <stdio.h>
#include "header.h"

int main() {
    Node *head = initList();

    printf("List before insertion: ");
    display(head);

    printf("List after Insertion: ");
    insertatbeg(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertafter(head->next, 40);
    inseratposition(&head, 1, 770);
    insertatend(&head, 990);
    display(head);

    printf("Deletion at beg: ");
    deleteatbeg(&head);
    display(head);

    printf("Deletion at End: ");
    deleteatend(&head);
    display(head);

    printf("Deletion at Position: ");
    deleteatposition(&head, 3);
    display(head);

    int position = searchEle(head, 30);
    if (position != -1) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found!!!\n");
    }

    printf("After Updating Element: ");
    updateEle(head, 1, 777);
    display(head);

    printf("Length of list: %d\n", length(head));

    if (isPalindrome(head)) {
        printf("List is Palindrome\n");
    } else {
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
