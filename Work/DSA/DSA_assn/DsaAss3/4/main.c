#include "heap.h"

int main()
{
    int n;
    scanf("%d", &n);

    Heap H;
    H = CreateHeap(n);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        InsertHeap(H, arr[i]);
        // printf("inserted in heap\n");
    }

    int *ans;
    ans = PrintDeArr(H, arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
