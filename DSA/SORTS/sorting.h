#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdio.h>
#include<stdlib.h>

int * ShellSort(int* arr,int n);
int *InsertionSort(int *arr, int n);
int *BubbleSort(int * arr,int n);
int *SelectionSort(int *arr, int n);
int * IndirectSorting(int * arr,int n);
int * HeapSort( int * array2sort,int numelems);
void Heapify(int *array2sort,int i,int numelems);
int* CountSort(int *array2sort,int numelems);
void swap(int *a,int *b);

#endif


