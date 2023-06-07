#include "sort.h"

int main()
{
    int num_of_testcases;
    scanf("%lld", &num_of_testcases);

    for (int i = 0; i < num_of_testcases; i++)
    {
        int numelems;
        scanf("%lld", &numelems);

        int iterations;
        scanf("%lld", &iterations);

        int *arr;
        arr = (int *)malloc(sizeof(int) * numelems);

        for (int i = 0; i < numelems; i++)
        {
            scanf("%lld", &arr[i]);
        }

        int happiness_level;

        happiness_level = Happiness(arr, numelems, iterations);

        // printf("final array:-\n");
        // for (int p = 0; p < numelems; p++)
        // {
        //     printf("%lld ",);
        // }
        printf("%lld\n", happiness_level);

        free(arr);
    }
}