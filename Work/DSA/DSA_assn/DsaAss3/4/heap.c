#include "heap.h"


Heap CreateHeap(int cap)
{
    Heap H;
    H = (Heap)malloc(sizeof(struct stHeap));
    H->capacity = cap;
    H->elements = (int *)malloc(sizeof(int) * cap);
    H->current = 0;
    H->elements[0] = -999999;
    return H;
}

int IsFull(Heap H)
{
    return (H->current == H->capacity);
}

int IsEmpty(Heap H)
{
    return (H->current == 0);
}

void InsertHeap(Heap H, int x)
{
    int i;

    if (IsFull(H))
    {
        printf("heap is full\n");
        return;
    }

    for (i = ++H->current; H->elements[i / 2] > x; i = i / 2)
    {
        H->elements[i] = H->elements[i] = H->elements[i / 2];
    }

    H->elements[i] = x;
    return;
}

int MinEle(Heap H)
{
    int i, child;
    int minelement, last;

    if (IsEmpty(H))
    {
        {
            return H->elements[0];
        }
    }

    minelement = H->elements[1];
    last = H->elements[H->current];
    H->current--;
    for (i = 1; 2 * i <= H->current; i = child)
    {
        child = 2 * i;
        if ((child != H->current) && (H->elements[child + 1] < H->elements[child]))
        {
            child++;
        }

        if (last > H->elements[child])
        {
            H->elements[i] = H->elements[child];
        }

        else
            break;
    }

    H->elements[i] = last;
    return minelement;
}

int *PrintDeArr(Heap H, int *arr, int n)
{
    int trackarr = 0;
    int trackp = 0;
    int *p;
    p = (int *)malloc(sizeof(int) * (H->capacity));
    for (int i = 0; i < H->capacity; i++)
    {
        p[i] = -1;
    }
    int *ans;
    ans = (int *)malloc(sizeof(int) * (n));
    for (int i = 0; i < H->capacity; i++)
    {
        ans[i] = -1;
    }
    int trackans = 0;

    int num;
    num = MinEle(H);

    int flag=0;
    // printf("%d ", num);
    // printf("element removed\n");

    while (num != H->elements[0])
    {
        flag++;

        if (arr[trackarr] == num)
        {
            p[trackp] = num;
            // trackarr++;
            trackp++;
        }

        else
        {
            ans[trackans] = num;
            trackans++;
            trackarr++;
            int i = 0;
            while (p[i] != -1)
            {
                ans[trackans] = p[i];
                trackans++;
                trackarr++;
                p[i] = -1;
                i++;
            }
            trackp = 0;
        }

        if (flag == n )
        {
            if (arr[trackarr] == num)
            {
                // printf("%d ",ans[trackans]);
                // printf("%d ",ans[trackans-1]);
                // printf("%d ",num);
                // printf("\n");
                
                
                int temp = ans[trackans-1];
                ans[trackans-1] = num;
                ans[trackans] = temp;
            }
        }

        num = MinEle(H);

        // printf("%d ", num);
    }

    return ans;
}
