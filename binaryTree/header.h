typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

// Function prototypes
Node *createNode(int value);
Node *insertNode(Node *root);
void inorder(Node *p);
int rcount_leaf(Node *p);
int rcount_nonleaf(Node *p);
int Height(Node *p);

