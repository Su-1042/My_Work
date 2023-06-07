#include "sort.h"


void Merge_Original(struct marble *arr, int lower, int mid, int upper)
{

    struct marble *temp;
    temp = (struct marble *)malloc(sizeof(struct marble) * (upper - lower + 1));

    int l = lower;
    int r = mid + 1;
    int tracktemp = 0;

    while (l <= mid && r <= upper)
    {
        if (arr[l].originalnum == arr[r].originalnum)
        {
            if (arr[l].newnum < arr[r].newnum)
            {
                temp[tracktemp].originalnum = arr[l].originalnum;
                temp[tracktemp].newnum = arr[l].newnum;
                l++;
                tracktemp++;
            }

            else
            {
                temp[tracktemp].originalnum = arr[r].originalnum;
                temp[tracktemp].newnum = arr[r].newnum;
                r++;
                tracktemp++;
            }
        }

        else if (arr[l].originalnum < arr[r].originalnum)
        {
            temp[tracktemp].originalnum = arr[l].originalnum;
            temp[tracktemp].newnum = arr[l].newnum;
            l++;
            tracktemp++;
        }

        else
        {
            temp[tracktemp].originalnum = arr[r].originalnum;
            temp[tracktemp].newnum = arr[r].newnum;
            r++;
            tracktemp++;
        }
    }

    if (l > mid && r <= upper)
    {
        for (int i = r; i <= upper; i++)
        {
            temp[tracktemp].originalnum = arr[i].originalnum;
            temp[tracktemp].newnum = arr[i].newnum;
            tracktemp++;
        }
    }

    else if (l <= mid && r > upper)
    {
        for (int i = l; i <= mid; i++)
        {
            temp[tracktemp].originalnum = arr[i].originalnum;
            temp[tracktemp].newnum = arr[i].newnum;
            tracktemp++;
        }
    }

    for (int i = lower; i <= upper; i++)
    {
        arr[i].originalnum = temp[i - lower].originalnum;
        arr[i].newnum = temp[i - lower].newnum;
    }

    return;
}

void MSDriver_Original(struct marble *arr, int lower, int upper)
{
    if (upper > lower)
    {
        int mid = ((lower + upper) / 2);
        MSDriver_Original(arr, lower, mid);
        MSDriver_Original(arr, mid + 1, upper);
        Merge_Original(arr, lower, mid, upper);
    }
    // printf("array merged\n");
}

void MergeSort_Original(struct marble *arr, int n)
{
    MSDriver_Original(arr, 0, n - 1);
}
