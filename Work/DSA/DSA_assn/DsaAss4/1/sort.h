#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

#define int long long 

void swap(int *a, int *b);
void Heapify(int *array2sort, int x, int numelems);
int Happiness(int *array2sort, int numelems, int movies);

#endif