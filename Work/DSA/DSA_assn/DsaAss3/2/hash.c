#include "hash.h"


int *Power(int num, int stringlength)
{
    int *hello;
    hello = (int *)malloc(sizeof(int) * stringlength);
    hello[0] = 1;
    for (int i = 1; i < stringlength; i++)
    {
        hello[i] = (num%mod * hello[i - 1]%mod) % mod;
    }
    return hello;
}

int *PrefixArray(const char *c, int stringlength, int *powerarray)
{

    int *PreArr;
    PreArr = (int *)malloc(sizeof(int) * stringlength);

    for (int pindex = 0; pindex < stringlength; pindex++)
    {

        PreArr[pindex] = ((c[pindex] - 96) * powerarray[pindex]%mod)%mod;
    }

    for (int i = 1; i < stringlength; i++)
    {
        PreArr[i] =(PreArr[i]%mod +PreArr[i - 1]%mod)%mod;
    }

    // printing
    // for (int i = 0; i < stringlength; i++)
    // {
    //     printf("%lld ", PreArr[i]);
    // }
    // printf("\n");

    return PreArr;
}

int *SuffixArray(char *c, int stringlength, int *powerarray)
{
    int *SufArr;
    SufArr = (int *)malloc(sizeof(int) * stringlength);

    for (int pindex = (stringlength - 1); pindex >= 0; pindex--)
    {
        SufArr[pindex] = ((c[pindex] - 96) * powerarray[(stringlength - 1) - pindex]%mod) % mod;
    }

    for (int i = (stringlength - 2); i >= 0; i--)
    {
        SufArr[i] =(SufArr[i]%mod+ SufArr[i + 1]%mod)%mod;
    }

    return SufArr;
}
