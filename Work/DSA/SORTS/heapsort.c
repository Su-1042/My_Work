#include "sorting.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// the heap is having zero indexing and hence the left child will be at 2i+1 sand the right child will bve at 2i+2
void Heapify(int *array2sort, int i, int numelems)
{
    int x = 2 * i + 1;
    while (x < numelems)
    {
        if (x + 1 < numelems)
        {
            if (array2sort[x + 1] > array2sort[x])
            {
                x = x + 1;
            }
        }

        // because the rest of the heap is anyways already sort
        if (array2sort[i] >= array2sort[x])
        {
            return;
        }

        swap(&array2sort[x], &array2sort[0]);
        i = x;
        x = 2 * i + 1;
    }
}

int *HeapSort(int *array2sort, int numelems)
{
    // building the max heap
    //(numelems/2)-1 will give the index of the lowest element
    for (int i = (numelems / 2) - 1; i >= 0; i--)
    {
        Heapify(array2sort, i, numelems);
    }

    // sorting it
    while (numelems > 1)
    {
        swap(&array2sort[0], &array2sort[numelems - 1]);
        numelems--;
        Heapify(array2sort, 0, numelems);
    }

    return array2sort;
}
