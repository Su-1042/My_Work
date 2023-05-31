#include "sorting.h"

// to perform insertion sort in descending just take the 
int *InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int temp = arr[i];

        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = temp;

        for (int p = 0; p < n; p++)
        {
            printf("%d ", arr[p]);
        }
        printf("\n");
    }

    return arr;
}



