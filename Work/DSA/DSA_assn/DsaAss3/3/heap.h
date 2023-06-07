#ifndef _HEAP_H
#define _HEAP_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stHeap *Heap;

struct stHeap
{
    long long int current;
    long long int capacity;
    long long int *elements;
};

Heap CreateHeap(long long int cap);
long long int IsFull(Heap H);
long long int IsEmpty(Heap H);
void InsertHeap(Heap H, long long int x);
long long int MinEle(Heap H);
void FreeHeap(Heap H);

#endif