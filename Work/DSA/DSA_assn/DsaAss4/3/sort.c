#include "sort.h"

int stringlen(char *string)
{
    int count = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int comparestrings(struct bisleri s1, struct bisleri s2)
{
    int strlens1;
    int strlens2;

    strlens1 = stringlen(s1.c); 
    strlens2 = stringlen(s2.c); 

    // printf("%d\n", strlens1);
    // printf("%d\n", strlens2);

    int flag = 0;

    if (strlens1 >= strlens2)
    {
        for (int i = 0; i < strlens2; i++)
        {
            if (s1.c[i] == s2.c[i])
                continue;

            // even position
            else if (i % 2 != 0)
            {
                if (s1.c[i] < s2.c[i])
                {
                    flag = 1;
                    return 1;
                }

                else
                {
                    return 0;
                }
            }

            // odd position
            else if (i % 2 == 0)
            {
                if (s1.c[i] > s2.c[i])
                {
                    flag = 1;
                    return 1;
                }

                else
                {
                    return 0;
                }
            }
        }

        if (flag == 0)
        {
            if (strlens2 % 2 != 0)
            {
                return 1;
            }
        }

    }

    else if (strlens1 < strlens2)
    {
        for (int i = 0; i < strlens1; i++)
        {
            if (s1.c[i] == s2.c[i])
                continue;

            // 0 indexing hai isiliye
            //  odd position
            else if (i % 2 == 0)
            {
                if (s1.c[i] > s2.c[i])
                {
                    flag = 1;
                    return 1;
                }

                else
                {
                    return 0;
                }
            }

            // even position
            else if (i % 2 != 0)
            {
                if (s1.c[i] < s2.c[i])
                {
                    flag = 1;
                    return 1;
                }

                else
                {
                    return 0;
                }
            }
        }

        if (flag == 0)
        {
            if (strlens1 % 2 == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

void printdict(int n, word words)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", words[i].c);
    }
}


void Merge(word arr, int lower, int mid, int upper)
{

    word temp;
    temp = (word )malloc(sizeof(struct bisleri) * (upper - lower + 1));

    int l = lower;
    int r = mid + 1;
    int tracktemp = 0;

    while (l <= mid && r <= upper)
    {
        if (comparestrings(arr[l],arr[r])==0)
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
}

void MSDriver(word arr, int lower, int upper)
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

void MergeWords(word arr, int n)
{
    //  printf("elements scanned\n");
    MSDriver(arr, 0, n - 1);

    //  printf("elements scanned\n");
    printdict(n, arr);
}


