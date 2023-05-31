#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int lower, int mid, int upper)
{

    int *temp;
    temp = (int *)malloc(sizeof(int) * (upper - lower + 1));

    int l = lower;
    int r = mid + 1;
    int tracktemp = 0;

    while (l <= mid && r <= upper)
    {
        if (arr[l] < arr[r])
        {
            temp[tracktemp] = arr[l];
            l++;
            tracktemp++;
        }

        else
        {
            temp[tracktemp] = arr[r];
            r++;
            tracktemp++;
        }
    }

    if (l > mid && r <= upper)
    {
        for (int i = r; i <= upper; i++)
        {
            temp[tracktemp] = arr[i];
            tracktemp++;
        }
    }

    else if (l <= mid && r > upper)
    {
        for (int i = l; i <= mid; i++)
        {
            temp[tracktemp] = arr[i];

            tracktemp++;
        }
    }



    for (int i = lower; i <= upper; i++)
    {
        arr[i] = temp[i-lower];
    }
    return;
}

void MSDriver(int *arr, int lower, int upper)
{
    if (upper > lower)
    {
        int mid = ((lower + upper) / 2);
        MSDriver(arr, lower, mid);
        MSDriver(arr, mid + 1, upper);
        Merge(arr, lower, mid, upper);
    }
    // printf("array merged\n");
}

void MergeSort(int *arr, int n)
{
    //  printf("elements scanned\n");
    MSDriver(arr, 0, n - 1);

    //  printf("elements scanned\n");

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

    // printf("elements scanned\n");

    MergeSort(arr, n);
}