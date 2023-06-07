#include "heap.h"

long long int main()
{
    long long int count = 0;
    long long int sum = 0;
    long long int nobnums;

    scanf("%lld", &nobnums);

    Heap H;
    H = CreateHeap(nobnums);

    long long int *arr;
    arr = (long long int *)malloc(sizeof(long long int) * nobnums);

    long long int flag = 0;
    long long int trackarr = 0;

    for (long long int i = 0; i < nobnums; i++)
    {
        long long int num;
        scanf("%lld", &num);
        if (num > 0)
            flag = 1;

        if (flag == 1)
        {
            arr[trackarr] = num;
            trackarr++;
        }
    }

    // printf("%d",trackarr);

    for (long long int i = 0; i < trackarr; i++)
    {
        if (arr[i] >= 0)
        {
            sum += arr[i];
            count++;
        }

        else
        {
            InsertHeap(H, arr[i]);

            if (sum + arr[i] >= 0)
            {
                sum=sum+arr[i];
                count++;
            }

            else
            {
                long long int some;
                some=MinEle(H);
                if (arr[i]>some)
                {
                    sum =sum-some;
                    sum=sum+arr[i];
                }
            }
        }
    }

    FreeHeap(H);

    printf("%lld\n", count);
    return 0;
}
