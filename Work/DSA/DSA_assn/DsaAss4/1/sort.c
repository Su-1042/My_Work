#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// the heap is having zero indexing and hence the left child will be at 2i+1 sand the right child will bve at 2i+2
void Heapify(int *array2sort, int x, int numelems)
{
    int y = 2 * x + 1;

    while (y < numelems)
    {
        if (y + 1 < numelems)
        {
            if (array2sort[y + 1] > array2sort[y])
            {
                y = y + 1;
            }
        }

        if (array2sort[x] >= array2sort[y])
        {
            return;
        }

        swap(&array2sort[x], &array2sort[y]);
        x = y;
        y = 2 * x + 1;
    }
}

int Happiness(int *array2sort, int numelems, int movies)
{
    int happy_level = 0;
    // building the max heap
    //(numelems/2)-1 will give the index of the lowest element
    for (int i = (numelems / 2) - 1; i >= 0; i--)
    {
        Heapify(array2sort, i, numelems);
    }

    for (int i = 0; i < movies; i++)
    {
        if(array2sort[0] <= 0)
            break;
        happy_level += array2sort[0];
        // printf("%lld \n",happy_level);
        array2sort[0]--;
        Heapify(array2sort, 0, numelems);
    }
    return happy_level;
}
