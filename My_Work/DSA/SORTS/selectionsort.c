// worst case time complexity is O(n^2)
// average time complexity is n^2
// space complexity is 1 as no new space is allocated

// STABILITY OF THE ARRAY
// stable means that in the order that they were added then they will be present in the sorted array
// say 9 is the minimum in an arraya= and there are two nines then let them be 9(1 inserted first) and 9(2 is inserted later)
// if the order is miantained in the sorting algorithm then that algo will be stable

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int *SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minimum = arr[i];
        int minindex = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < minimum)
            {
                minimum = arr[j];
                minindex = j;
            }
        }

        swap(&arr[i], &arr[minindex]);

    }
}
