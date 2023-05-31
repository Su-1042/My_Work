#include "sorting.h"


int * IndirectSorting(int * arr,int n)
{
    int **ptrarray;
    ptrarray=(int **)malloc(sizeof(int*)*n);

    for (int i=0;i<n;i++)
    {
        ptrarray[i]=&arr[i];
    }

    int j;
    for (int i=1;i<n;i++)
    {
        int* temp=&arr[i];
        j=i;
        while(j>0&& *temp<*ptrarray[j-1])
        {
            ptrarray[j]=ptrarray[j-1];
            j--;

        }

        ptrarray[j]=temp;
    }


    printf("final sorted array:-\n");
    for (int k=0;k<n;k++)
    {
        printf("%d ",*ptrarray[k]);
    }

    printf("\n");

}