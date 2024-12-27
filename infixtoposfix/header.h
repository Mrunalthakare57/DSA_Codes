#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
} Stack;

int prec(char c);
void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void infix_to_postfix(char *s, char *ans);
