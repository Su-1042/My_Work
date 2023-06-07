#include "sort.h"

int main()
{
    int num_testcases;
    scanf("%d", &num_testcases);

    for (int i = 0; i < num_testcases; i++)
    {
        int schools;
        int num_players;

        scanf("%d", &schools);
        scanf("%d", &num_players);

        int **players = (int **)malloc(sizeof(int *) * schools);

        for (int d = 0; d < schools; d++)
        {
            players[d] = (int *)malloc(sizeof(int) * num_players);
        }

        for (int e = 0; e < num_players; e++)
        {
            for (int j = 0; j < schools; j++)
            {
                scanf("%d", &players[j][e]);
            }
        }

        int chosenschool;
        scanf("%d", &chosenschool);
        chosenschool = chosenschool - 1;

        if (schools == 1)
        {
            printf("%d\n", num_players);
        }
        else
        {

            int wins;
            wins = find_wins(players, schools, num_players, chosenschool);

            printf("%d\n", wins);
        }

        freetheplayers(players, schools);
    }
}