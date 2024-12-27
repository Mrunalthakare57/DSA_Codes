#include <stdio.h>
#include "header.h"

int main() {
    Node *head = initList();
    printf("List before insertion: ");
    display(head);

    printf("List after insertion: \n");
    insertatbeg(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertafter(head, 40);
    insertatposition(&head, 2, 15);
    display(head);

    deleteatbeg(&head);
    printf("After deleting at beginning: \n");
    display(head);

    deleteatend(&head);
    printf("After deleting at end: \n");
    display(head);

    deleteNode(&head, head->next);
    printf("After deleting a node: \n");
    display(head);

    int position = searchEle(head, 20);
    if (position != -1) {
        printf("Element found at %d position: \n", position);
    } else {
        printf("Element not found\n");
    }

    insertatend(&head, 5);
    updatele(head, 1, 15);
    printf("After Updation: ");
    display(head);

    printf("Length of list is: %d\n", length(head));
    if (ispalindrome(head)) {
        printf("List is Palindrome\n");
    } else {
        printf("List is not palindrome\n");
    }

    removeduplicates(head);
    printf("After Removing duplicates: ");
    display(head);

    sortedLink(&head);
    printf("After Sorting: ");
    display(head);

    return 0;
}
