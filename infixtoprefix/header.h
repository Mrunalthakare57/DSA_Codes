#define MAX 100

typedef struct
{
    char data[MAX];
    int top;
} Stack;

int prec(char c);
void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, char value);
char pop(Stack *s);
char peek(Stack *s);
void reverse(char *exp);
void infix_to_prefix(char *s, char *ans);
