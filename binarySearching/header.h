typedef struct Array
{
    int totalSize;
    int usedSize;
    int *elements;
} Array;

void initArray(Array *arr, int totalSize);
void insertElements(Array *arr);
int binarySearch(Array *arr, int key);
void sort(Array *arr);
void display(Array *arr);
