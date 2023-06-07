#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main()
{
    int number_of_operations2BPErformed;
    scanf("%d", &number_of_operations2BPErformed);

    for (int i = 0; i < number_of_operations2BPErformed; i++)
    {
        char operationname[20];

        scanf("%s", operationname);

        if (operationname[4] == '1')
        {
            int stringlength;
            scanf("%d", &stringlength);
            char string2Breversed[stringlength];
            scanf("%s", string2Breversed);
            char *str;
            str = string2Breversed;
            reverseString(str, stringlength);
        }

        else if (operationname[4] == '2')
        {
            int stringlength;
            scanf("%d", &stringlength);
            char string2Bcompressed[stringlength];
            scanf("%s", string2Bcompressed);
            char *str;
            str = string2Bcompressed;
            char *track = compressString(str, stringlength);
            free(track);
            printf("\n");
        }

        else if (operationname[4] == '3')
        {
            int length;
            scanf("%d", &length);
            int *arr;
            arr = (int *)malloc(length * sizeof(int));

            for (int i = 0; i < length; i++)
            {
                scanf("%d", &arr[i]);
            }

            int *ptr2finalarray;

            ptr2finalarray = uniqueElements(arr, length);
 
            for (int i = 0; i < length; i++)
            {
                int index = arr[i];
                if (ptr2finalarray[index] != 0)
                {
                    printf("%d ",index);
                    ptr2finalarray[index]=0;
                
                }
    
            }
            printf("\n");

              free (arr);
              free(ptr2finalarray);
        }

        else if (operationname[4] == '4')
        {
            int NumRow;
            int NumCol;
            scanf("%d %d", &NumRow, &NumCol);
            // allocating memory to the array of pointers
            int **matrix;
            matrix = (int **)malloc(NumRow * sizeof(int *));
            for (int i = 0; i < NumRow; i++)
            {
                //  int *matrix[i];
                matrix[i] = (int *)malloc(NumCol * sizeof(int));
            }

            for (int i = 0; i < NumRow; i++)
            {
                for (int j = 0; j < NumCol; j++)
                {
                    scanf("%d", &matrix[i][j]);
                }
            }

            int **transposematrix;
            transposematrix = transpose(matrix, NumRow, NumCol);

            for (int i = 0; i < NumCol; i++)
            {
                for (int j = 0; j < NumRow; j++)
                {
                    printf("%d ", transposematrix[i][j]);
                }
                printf("\n");
            }

            // freeing the arrays
            for (int i = 0; i < NumRow; i++)
            {
                free(matrix[i]);
            }
            free(matrix);

            for (int i = 0; i < NumCol; i++)
            {
                free(transposematrix[i]);
            }
            free(transposematrix);
        }
    }
}