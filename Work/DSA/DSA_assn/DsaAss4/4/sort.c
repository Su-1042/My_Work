#include "sort.h"

void freetheplayers(int **array, int rows)
{

    for (int i = 0; i < rows; ++i)
    {
        free(array[i]);
    }

    free(array);
}

void Merge(int *arr, int lower, int mid, int upper)
{

    int *temp;
    temp = (int *)malloc(sizeof(int) * (upper - lower + 1));

    int l = lower;
    int r = mid + 1;
    int tracktemp = 0;

    while (l <= mid && r <= upper)
    {
        if (arr[l] < arr[r])
        {
            temp[tracktemp] = arr[l];
            l++;
            tracktemp++;
        }

        else
        {
            temp[tracktemp] = arr[r];
            r++;
            tracktemp++;
        }
    }

    if (l > mid && r <= upper)
    {
        for (int i = r; i <= upper; i++)
        {
            temp[tracktemp] = arr[i];
            tracktemp++;
        }
    }

    else if (l <= mid && r > upper)
    {
        for (int i = l; i <= mid; i++)
        {
            temp[tracktemp] = arr[i];

            tracktemp++;
        }
    }

    for (int i = lower; i <= upper; i++)
    {
        arr[i] = temp[i - lower];
    }
    return;

    free(temp);
}

void MSDriver(int *arr, int lower, int upper)
{
    if (upper > lower)
    {
        int mid = ((lower + upper) / 2);
        MSDriver(arr, lower, mid);
        MSDriver(arr, mid + 1, upper);
        Merge(arr, lower, mid, upper);
    }
    // printf("array merged\n");
}

void MergeSort(int *arr, int n)
{
    //  printf("elements scanned\n");
    MSDriver(arr, 0, n - 1);

    //  printf("elements scanned\n");

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
}

int find_wins(int **players, int schools, int num_players, int chosenschool)
{
    int wins = 0;
    int *chosen;
    chosen = (int *)malloc(sizeof(int) * num_players);

    int *maxincol_apartfromchosenschool;
    maxincol_apartfromchosenschool = (int *)malloc(sizeof(int) * (num_players));
    int track = 0;

    for (int i = 0; i < num_players; i++)
    {
        chosen[i] = players[chosenschool][i];
    }

    for (int j = 0; j < num_players; j++)
    {
        int max = 0;
        // printf("%d\n",players[0][2]);
        if (chosenschool == 0)
            max = players[1][j];
        else
            max = players[0][j];

        for (int k = 0; k < schools; k++)
        {
            if (k != chosenschool)
            {
                if (players[k][j] > max)
                    max = players[k][j];
            }
        }

        maxincol_apartfromchosenschool[track] = max;
        track++;
    }

    MergeSort(chosen, num_players);
    MergeSort(maxincol_apartfromchosenschool, num_players);

    int trackmax = num_players - 1;
    int trackchosen = num_players - 1;

    while (trackmax >= 0)
    {
        if (chosen[trackchosen] > maxincol_apartfromchosenschool[trackmax])
        {
            trackchosen--;
            trackmax--;
            wins++;
        }

        else
        {
            trackmax--;
        }
    }

    free(chosen);
    free(maxincol_apartfromchosenschool);

    return wins;
}
