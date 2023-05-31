#include "sorting.h"

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

    int *ansarr;

    // ansarr=ShellSort(arr,n);
    // ansarr = HeapSort(arr, n);
    // ansarr = BubbleSort(arr, n);
    // ansarr = SelectionSort(arr,n);
    // ansarr = InsertionSort(arr, n);
    // ansarr = MergeSort();
    // ansarr = QuickSort();
    ansarr = CountSort(arr, n);

    // IndirectSorting(arr,n);
    // printing for indirects sorting will happen inside the function call only
    

    // //printing for all other sortings
    printf("final array:-\n");
    for (int p = 0; p < n; p++)
    {
        printf("%d ", ansarr[p]);
    }
    printf("\n");

    free(arr);
}