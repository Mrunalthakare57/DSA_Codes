typedef struct Array
{
    int totalSize; // Previously tsize
    int usedSize;  // Previously usize
    int *elements; // Previously ptr
} Array;

void initArray(Array *array, int totalSize);
void insertElements(Array *array);
void quickSort(Array *array);
void display(Array *array);
