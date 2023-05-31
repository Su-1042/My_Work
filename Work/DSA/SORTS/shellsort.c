#include "sorting.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *ShellSort(int *arr, int n)
{
    int gap, temp, i, j;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            // int flag=0;
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
           
                // arr[j] = arr[j - gap];
                swap(&arr[j],&arr[j-gap]);
            }

            

            // arr[j] = temp;
        }
    }

    return arr;
}