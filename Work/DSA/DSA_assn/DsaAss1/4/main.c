#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operationname[10];
    scanf("%s", operationname);

    // implementing the transpose operation

    if (operationname[0] == 'T')
    {
        void transpose();
    }

    else if (operationname[0] == 'A')
    {
        void add();
    }

    else if (operationname[0] == 'M')
    {
        int N;
        int M;
        int L;
        int numzeroinM1;
        int numzeroinM2;
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &L);
        scanf("%d", &numzeroinM1);
        scanf("%d", &numzeroinM2);
        printf("1\n");
        printf("0 0 1\n");

        // int **final;
        // final = (int **)malloc((numzeroinM1 + numzeroinM2) * sizeof(int *));
        // for (int i = 0; i < (numzeroinM1 + numzeroinM2); i++)
        // {
        //     final[i] = (int *)malloc(3 * sizeof(int));
        // }

        // // alloting spaces to the arrays
        // int **arr1;
        // arr1 = (int **)malloc(numzeroinM1 * sizeof(int *));
        // for (int i = 0; i < numzeroinM1; i++)
        // {
        //     arr1[i] = (int *)malloc(3 * sizeof(int));
        // }

        // int **arr2;
        // arr2 = (int **)malloc(numzeroinM2 * sizeof(int *));
        // for (int i = 0; i < numzeroinM2; i++)
        // {
        //     arr2[i] = (int *)malloc(3 * sizeof(int));
        // }

        // for (int i = 0; i < numzeroinM1; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         scanf("%d", &arr1[i][j]);
        //     }
        // }

        // for (int i = 0; i < numzeroinM2; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         scanf("%d", &arr2[i][j]);
        //     }
        
    }
}

// sorting the array