typedef struct Array
{
    int totalSize;
    int usedSize;
    int *elements;
} Array;

void initArray(Array *arr, int totalSize);
void insertElements(Array *arr);
int linearSearch(Array *arr, int key);
void display(Array *arr);
