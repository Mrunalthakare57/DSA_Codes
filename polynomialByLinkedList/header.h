typedef struct Node
{
    int coef;
    int expo;
    struct Node *next;
} Node;

Node *create(int coef, int expo);
Node *insertTerm(Node *head, int coef, int expo);
void display(Node *head);
Node *addPoly(Node *p1, Node *p2);
Node *subpoly(Node *p1, Node *p2);
