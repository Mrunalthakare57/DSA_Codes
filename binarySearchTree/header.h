struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

extern struct Node *root;

void insert(int key);
void inorder(struct Node *p);
void preorder(struct Node *p);
void postorder(struct Node *p);
struct Node *search(int key);
int Height(struct Node *p);
struct Node *InPre(struct Node *p);
struct Node *Insucc(struct Node *p);
struct Node *Delete(struct Node *p, int key);
int count_leaf(struct Node *root);
int count_nonleaf(struct Node *root);
int NHeight(struct Node *root);

