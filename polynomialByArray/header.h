typedef struct term {
    int coef;
    int expo;
} term;

typedef struct poly {
    term *t;
    int num;
} poly;

poly *create(int num);
void set(poly *p, int i, int c, int e);
void sort(poly *p);
void display(poly *p);
poly *add(poly *p1, poly *p2);
poly *sub(poly *p1, poly *p2);

