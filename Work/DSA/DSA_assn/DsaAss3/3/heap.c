#include "heap.h"

Heap CreateHeap(long long int cap)
{
    Heap H;
    H = (Heap)malloc(sizeof(struct stHeap));
    H->capacity = cap;
    H->elements = (long long int *)malloc(sizeof(long long int) * (cap + 5));
    H->current = 0;
    H->elements[0] = -999999;
    return H;
}

long long int IsFull(Heap H)
{
    return (H->current == H->capacity);
}

long long int IsEmpty(Heap H)
{
    return (H->current == 0);
}

void InsertHeap(Heap H, long long int x)
{
    long long int i;

    if (IsFull(H))
    {
        // printf("heap is full\n");
        return;
    }

    for (i = ++H->current; H->elements[i / 2] > x; i = i / 2)
    {
        H->elements[i] = H->elements[i / 2];
    }

    H->elements[i] = x;
    return;
}

long long int MinEle(Heap H)
{
    long long int i, child;
    long long int minelement, last;
    if (IsEmpty(H))
    {
        return H->elements[0];
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

void FreeHeap(Heap H)
{
    free(H->elements);
    free(H);
}
