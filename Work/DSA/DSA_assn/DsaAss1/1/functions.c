#include <stdio.h>
#include <stdlib.h>

// OPER1
void swapletters(char *start, char *end)
{
    char temp;
    temp = *start;
    *start = *end;
    *end = temp;
}

void reverseString(char *str, int length)
{

    char *start;
    char *end;

    start = str;
    end = str + length - 1;

    for (int i = 0; i < (length + 1) / 2; i++)
    {
        swapletters(start, end);
        start++;
        end--;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}

// OPER2
// try using sprintf alternately if this doesnt work
char *compressString(char *arr, int length)
{
    char *track;
    char *ptr;
    ptr = (char *)malloc(length * sizeof(char));
    track = arr;
    int count = 0;
    while (*arr != '\0')
    {
        if (*track == *arr)
        {
            arr++;
            count++;
            continue;
        }

        else
        {
            printf("%c", *track);
            printf("%d", count);
            // *ptr = *track;
            // ptr ++;
            track = arr;
            // *ptr=count;
            count = 0;
            // ptr++;
        }
    }
    printf("%c", *track);
    printf("%d", count);
    return ptr;
}

// OPER3

int *uniqueElements(int *arr, int length)
{
    int *track;
    track = arr;

    int *checkarray;
    checkarray = (int *)calloc(10000, sizeof(int));
    // track = checkarray;

    for (int i = 0; i < length; i++)
    {
        checkarray[*arr]++;
        arr++;
    }
    arr = track;
    return checkarray;
}

int **transpose(int **matrix, int NumRow, int NumCol)
{
    int Transrow = NumCol;
    int Transcol = NumRow;
    int **transposematrix;
    transposematrix = (int **)malloc(Transrow * sizeof(int *));
    for (int i = 0; i < Transrow; i++)
    {
        transposematrix[i] = (int *)malloc(Transcol * sizeof(int));
    }

    for (int i = 0; i < Transcol; i++)
    {
        for (int j = 0; j < Transrow; j++)
        {
            transposematrix[j][i] = matrix[i][j];
        }
    }

    return transposematrix;
}
