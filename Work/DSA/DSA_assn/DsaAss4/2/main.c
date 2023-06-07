#include"sort.h"

int main()
{

    int test_cases;
    scanf("%d", &test_cases);
    for (int k = 0; k < test_cases; k++)
    {
        int num_marbles;
        scanf("%d", &num_marbles);

        struct marble *marbles;
        marbles = (struct marble *)malloc(sizeof(struct marble) * num_marbles);

        for (int i = 0; i < num_marbles; i++)
        {
            scanf("%d", &marbles[i].originalnum);
        }

        for (int i = 0; i < num_marbles; i++)
        {
            scanf("%d", &marbles[i].newnum);
        }

        // handle the case when all the a are equal

        MergeSort_Original(marbles, num_marbles);

        int *J2;
        J2 = (int *)malloc(sizeof(int) * num_marbles);
        // printf("\n");

        if (marbles[0].newnum <= marbles[0].originalnum)
            J2[0] = marbles[0].newnum;

        else
            J2[0] = marbles[0].originalnum;

        for (int i = 1; i < num_marbles; i++)
        {
            if (marbles[i].newnum >= J2[i - 1] && marbles[i].originalnum >= J2[i - 1])
            {
                if (marbles[i].newnum <= marbles[i].originalnum)
                    J2[i] = marbles[i].newnum;

                else
                    J2[i] = marbles[i].originalnum;
            }

            else
                J2[i] = marbles[i].originalnum;
        }

        printf("%d %d\n", marbles[num_marbles - 1].originalnum, J2[num_marbles - 1]);
    }
}

