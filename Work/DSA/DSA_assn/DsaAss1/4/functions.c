#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void transpose()
{
    int totalrows;
    int totalcols;
    int numberofnonzeros;
    scanf("%d", &totalrows);
    scanf("%d", &totalcols);
    scanf("%d", &numberofnonzeros);

    int **array;
    array = (int **)malloc(numberofnonzeros * sizeof(int *));
    for (int i = 0; i < numberofnonzeros; i++)
    {
        array[i] = (int *)malloc(3 * sizeof(int));
    }

    for (int i = 0; i < numberofnonzeros; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < numberofnonzeros; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (array[i][j] != array[i][j + 1])
            {
                int temp;
                temp = array[i][j];
                array[i][j] = array[i][j + 1];
                array[i][j + 1] = temp;
            }
        }
    }

    int k = 0;

    for (int i = 0; i < numberofnonzeros; i++)
    {

        for (int j = i; j < numberofnonzeros; j++)
        {
            // printf("%d",array[i][k]);

            if (array[i][k] >= array[j][k])
            {
                swap(&array[i][k], &array[j][k]);
                swap(&array[i][k + 1], &array[j][k + 1]);
                swap(&array[i][k + 2], &array[j][k + 2]);
            }
        }
    }

    for (int i = 0; i < numberofnonzeros; i++)
    {

        for (int j = i; j < numberofnonzeros; j++)
        {

            if (array[i][k] == array[j][k])
            {
                if (array[i][k + 1] > array[j][k + 1])
                {
                    swap(&array[i][k], &array[j][k]);
                    swap(&array[i][k + 1], &array[j][k + 1]);
                    swap(&array[i][k + 2], &array[j][k + 2]);
                }
            }
        }
    }

    printf("%d\n", numberofnonzeros);
    for (int i = 0; i < numberofnonzeros; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < numberofnonzeros; i++)
    {
        free(array[i]);
    }
    free(array);
}

void add()
{
    int rows;
    int cols;
    int numzeroinM1;
    int numzeroinM2;

    scanf("%d", &rows);
    scanf("%d", &cols);
    scanf("%d", &numzeroinM1);
    scanf("%d", &numzeroinM2);

    arr array1[numzeroinM1 + 1];
    arr array2[numzeroinM2 + 1];

    for (int i = 0; i < numzeroinM1; i++)
    {
        scanf("%d %d %d", &array1[i].r, &array1[i].c, &array1[i].value);
    }
    for (int i = 0; i < numzeroinM2; i++)
    {
        scanf("%d %d %d", &array2[i].r, &array2[i].c, &array2[i].value);
    }

    int k1 = 0, k2 = 0;
    int count = 0;

    for (int i = 0;; i++)
    {

        if (array1[k1].r < array2[k2].r)
        {
            // printf("%d %d %d\n",array1[k1].r, array1[k1].c, array1[k1].value);
            count++;
            k1++;
        }
        else if (array1[k1].r > array2[k2].r)
        {
            // printf("%d %d %d\n",array2[k2].r, array2[k2].c, array2[k2].value);
            k2++;
            count++;
        }
        else if (array1[k1].c < array2[k2].c)
        {
            //  printf("%d %d %d\n",array1[k1].r, array1[k1].c, array1[k1].value);
            count++;
            k1++;
        }
        else if (array1[k1].c > array2[k2].c)
        {
            //  printf("%d %d %d\n",array2[k2].r, array2[k2].c, array2[k2].value);
            k2++;
            count++;
        }
        else
        {
            if ((array2[k2].value + array1[k1].value) != 0)
            {
                //  printf("%d %d %d\n",array2[k2].r, array2[k2].c, array2[k2].value+array1[k1].value);
                count++;
            }
            k1++;
            k2++;
        }

        if (k1 >= numzeroinM1 || k2 >= numzeroinM2)
        {
            break;
        }
    }

    while (k2 != numzeroinM2)
    {
        count++;
        k2++;
    }
    while (k1 != numzeroinM1)
    {
        count++;
        k1++;
    }

    printf("%d\n", count);
    k1 = 0;
    k2 = 0;
    for (int i = 0;; i++)
    {

        if (array1[k1].r < array2[k2].r)
        {
            printf("%d %d %d\n", array1[k1].r, array1[k1].c, array1[k1].value);
            k1++;
        }
        else if (array1[k1].r > array2[k2].r)
        {
            printf("%d %d %d\n", array2[k2].r, array2[k2].c, array2[k2].value);
            k2++;
        }
        else if (array1[k1].c < array2[k2].c)
        {
            printf("%d %d %d\n", array1[k1].r, array1[k1].c, array1[k1].value);
            k1++;
        }
        else if (array1[k1].c > array2[k2].c)
        {
            printf("%d %d %d\n", array2[k2].r, array2[k2].c, array2[k2].value);
            k2++;
        }
        else
        {
            if ((array2[k2].value + array1[k1].value) != 0)
            {
                printf("%d %d %d\n", array2[k2].r, array2[k2].c, array2[k2].value + array1[k1].value);
                count++;
            }
            k1++;
            k2++;
        }
        if (k1 == numzeroinM1 || k2 == numzeroinM2)
        {
            break;
        }
    }
    while (k2 != numzeroinM2)
    {
        printf("%d %d %d\n", array2[k2].r, array2[k2].c, array2[k2].value);
        k2++;
    }
    while (k1 != numzeroinM1)
    {
        count++;
        printf("%d %d %d\n", array1[k1].r, array1[k1].c, array1[k1].value);
        k1++;
    }
}


void multiply(){
    
}