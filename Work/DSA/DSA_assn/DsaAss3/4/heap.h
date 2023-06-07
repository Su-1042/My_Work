#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stHeap *Heap;

struct stHeap
{
    int current;
    int capacity;
    int *elements;
};

Heap CreateHeap(int cap);
int IsFull(Heap H);
int IsEmpty(Heap H);
void InsertHeap(Heap H, int x);
int MinEle(Heap H);
int *PrintDeArr(Heap H, int *arr, int n);

#endif