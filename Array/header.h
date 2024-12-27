
#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int length;
} ArrayADT;

void initArray(ArrayADT *arr, int size);
void fillArray(ArrayADT *arr, int num_elements);
void display(ArrayADT *arr);
void insertEle(ArrayADT *arr, int element, int index);
void deleteEle(ArrayADT *arr, int index);
int searchEle(ArrayADT *arr, int element);
void updateEle(ArrayADT *arr, int index, int newEle);
int findMAX(ArrayADT *arr);
int findMIN(ArrayADT *arr);
void reverse(ArrayADT *arr);
void sortarray(ArrayADT *arr);
void appendEle(ArrayADT *arr, int element);
ArrayADT joinarrays(ArrayADT *arr1, ArrayADT *arr2);
void freeArray(ArrayADT *arr);
void mov_neg(ArrayADT *arr);

