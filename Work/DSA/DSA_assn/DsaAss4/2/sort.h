#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>

struct marble
{
    int originalnum;
    int newnum;
};

void Merge_Original(struct marble *arr, int lower, int mid, int upper);
void MergeSort_Original(struct marble *arr, int n);
void MSDriver_Original(struct marble *arr, int lower, int upper);

#endif