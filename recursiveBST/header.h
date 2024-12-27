typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

extern Node *root;

Node *Rinsert(Node *p, int key);
Node *Rsearch(Node *t, int key);
int rcount_leaf(Node *p);
int rcount_nonleaf(Node *p);
int Height(Node *p);
Node *InPre(Node *p);
Node *Insucc(Node *p);
Node *Delete(Node *p, int key);
void inorder(Node *p);

