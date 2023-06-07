#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

void freetheplayers(int **array, int rows);
void Merge(int *arr, int lower, int mid, int upper);
void MSDriver(int *arr, int lower, int upper);
void MergeSort(int *arr, int n);
int find_wins(int **players, int schools, int num_players, int chosenschool);

#endif