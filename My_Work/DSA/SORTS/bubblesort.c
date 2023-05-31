#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int *BubbleSort(int * arr,int n){

    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (arr[j]<arr[i])
            {
                swap(&arr[i],&arr[j]);
            }
        }
    }

    return arr;
}
