typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *initList();
Node *createNode(int data);
void insertatbeg(Node **head, int data);
void insertatend(Node **head, int data);
void insertafter(Node *prevnode, int data);
void insertatposition(Node **head, int position, int data);
void deleteatbeg(Node **head);
void deleteatend(Node **head);
void deleteNode(Node **head, Node *delnode);
void display(Node *head);
int searchEle(Node *head, int data);
int updatele(Node *head, int position, int element);
int length(Node *head);
int ispalindrome(Node *head);
void removeduplicates(Node *head);
void sortedLink(Node **head);

