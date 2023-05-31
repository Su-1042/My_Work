#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int *arr, int n)
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

        // for (int p = 0; p < n; p++)
        // {
        //     printf("%d ", arr[p]);
        // }
        // printf("\n");
    }
}

int median_of_3(int *arr, int lower, int upper)
{
    int i = lower;
    int j = upper;
    int mid = (i + j) / 2;

    int sorted[3];
    // find maxout of the three
    if (arr[i] > arr[mid] && arr[i] > arr[j])
    {
        sorted[2] = arr[i];
        if (arr[mid] > arr[j])
        {
            sorted[1] = arr[mid];
            sorted[0] = arr[j];
        }
        else
        {
            sorted[0] = arr[mid];
            sorted[1] = arr[j];
        }
    }
    if (arr[j] > arr[mid] && arr[j] > arr[i])
    {
        sorted[2] = arr[j];
        if (arr[i] > arr[mid])
        {
            sorted[1] = arr[i];
            sorted[0] = arr[mid];
        }
        else
        {
            sorted[0] = arr[i];
            sorted[1] = arr[mid];
        }
    }
    if (arr[mid] > arr[i] && arr[mid] > arr[j])
    {
        sorted[2] = arr[mid];
        if (arr[i] > arr[j])
        {
            sorted[1] = arr[i];
            sorted[0] = arr[j];
        }
        else
        {
            sorted[0] = arr[i];
            sorted[1] = arr[j];
        }
    }

    // printf("%d\n", arr[i]);
    // printf("%d\n", arr[j]);
    // printf("%d\n", arr[mid]);

    arr[i] = sorted[0];
    arr[j] = sorted[2];
    arr[mid] = sorted[1];

    // printf("%d\n", sorted[0]);
    // printf("%d\n", sorted[1]);
    // printf("%d\n", sorted[2]);

    return sorted[1];
}

// int FindIndex(int *sorted,1int to_find, int lower, int upper)
//
//     for (int i = 0; i < (upper - lower + 1); i++)
//     {
//         if (arr[i] == to_find)
//             return i;
//     }
// }

int QuickPart(int *arr, int pivot, int lower, int upper)
{
    int i = lower;
    int j = upper - 1;
    swap(&arr[upper], &arr[(upper + lower) / 2]);

    while (1)
    {
        while (arr[++i] < arr[pivot])
        {
        }
        while (arr[--j] > arr[pivot])
        {
        }

        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[upper], &arr[(upper + lower) / 2]);

    return i;
}

void QSDriver(int *arr, int lower, int upper)
{
    if (upper < 5)
        InsertionSort(arr, upper + 1);

    else
    {
        int pivot_value = median_of_3(arr, lower, upper);
        printf("%d\n", pivot_value);
        int pivot_index = QuickPart(arr, pivot_value, lower, upper);
        QSDriver(arr, lower, pivot_index - 1);
        QSDriver(arr, pivot_index + 1, upper);
    }
}

void QuickSort(int *arr, int n)
{
    QSDriver(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr;       
    arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    QuickSort(arr, n);
}