typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initList();
Node *createNode(int data);
void insertatbeg(Node **head, int data);
void insertatend(Node **head, int data);
void insertafter(Node *prevnode, int data);
void insertatposition(Node *head, int position, int data);
void deleteatbeg(Node **head);
void deleteatend(Node **head);
void deleteatpositon(Node **head, int position);
void display(Node *head);
int searchEle(Node *head, int data);
void updateele(Node *head, int position, int newdata);
int length(Node *head);
int isPalindrome(Node *head);
void removeduplicates(Node *head);
void sortLinkedList(Node **head);

