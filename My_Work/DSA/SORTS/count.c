#include "sorting.h"

// considering only the numbwrs from 0 to 9 are there
int *CountSort(int *array, int n)
{
    int k=10;
    int *freq = (int *)malloc(sizeof(int) * (k));
    int *ansarr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        freq[array[i]]++;
    }

    for (int i=1;i<k;i++)
    {
        freq[i]+=freq[i-1];
    }

    for (int i=0;i<n;i++)
    {
        ansarr[freq[array[i]]-1]=array[i];
        freq[array[i]]--;
    }

    return ansarr;
}