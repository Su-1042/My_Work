#include "hash.h"

int mod = 1e9+7;

int * MakeArr(int arrsize)
{
    int* arr;
    arr=(int *)malloc(sizeof(int)*arrsize);
    return arr;
}

signed main()
{
    int stringlength;
    int numofque;
    scanf("%lld", &stringlength);
    scanf("%lld", &numofque);
    char *c;
    c = (char *)malloc(sizeof(char) * (stringlength + 1));
    scanf("%s", c);

    int *powerarray;
    powerarray = MakeArr(stringlength);
    powerarray = Power(31, stringlength);

    int *PreArr;
    PreArr = MakeArr(stringlength);
    PreArr = PrefixArray(c, stringlength, powerarray);

    int *SufArr;
    SufArr = MakeArr(stringlength);
    SufArr = SuffixArray(c, stringlength, powerarray);

    for (int i = 0; i < numofque; i++)
    {
        int l;
        int r;

        scanf("%lld", &l);
        scanf("%lld", &r);

        // just to maintain the zero indexing, l=l-1 and r=r-1
        l = l - 1;
        r = r - 1;

        int pre = 0;
        int post = 0;

        if (l == r)
        {
            printf("YES\n");
            continue;
        }

        else if (l == 0 && r == (stringlength - 1))
        {
            pre = ((PreArr[r]%mod - PreArr[l]%mod)%mod + mod) % mod;
            post = ((SufArr[l]%mod - SufArr[r]%mod)%mod+ mod) % mod;
        }

        else if (l == 0)
        {
            // printf("l==0 here\n");
            // printf("%lld\n",powerarray[r]);
            // printf("%lld\n",PreArr[r]);
            pre = ((PreArr[r]%mod) *(powerarray[(stringlength-1)-r])%mod)%mod;
            post = (SufArr[l]%mod - SufArr[r + 1]%mod+ mod) % mod;
            // printf("%lld\n", pre);
            // printf("%lld\n", post);
        }

        else if (r == (stringlength - 1))
        {

            // printf("r==0 here\n");
            pre = ((PreArr[r]%mod - PreArr[l - 1]%mod)%mod+ mod)% mod;
            post = (SufArr[l]%mod * powerarray[l]%mod) % mod;
            // printf("%lld\n", pre);
            // printf("%lld\n", post);
            //while stroing them as so ejsut have a single for loop and imploement power and other stuff sililarly
            // create space to store the data;
        }

        else if ((stringlength - (r + 1)) == l)
        {

            pre = (((PreArr[r]%mod) - PreArr[l - 1]%mod)%mod+mod) % mod;
            post = ((SufArr[l]%mod - SufArr[r + 1]%mod)%mod+mod) % mod;
            // printf("%lld\n", pre);
            // printf("%lld\n", post);
        }

        else if ((stringlength - (r + 1)) < l)
        {

            pre = ((((PreArr[r]%mod) - PreArr[l - 1]%mod)%mod+mod)%mod * powerarray[stringlength-(r+1)]%mod ) % mod;
            post = ((SufArr[l]%mod - SufArr[r + 1]%mod)%mod+mod)* powerarray[l] % mod;
            // printf("%lld\n", pre);
            // printf("%lld\n", post);
        }

        else if ((stringlength - (r + 1)) > l)
        {

            pre = (((PreArr[r]%mod) - PreArr[l - 1]%mod)%mod+mod)*powerarray[stringlength-(r+1)] % mod;
            post = ((((SufArr[l]%mod - SufArr[r + 1]%mod)%mod+mod) * powerarray[l]%mod)) % mod;
            // printf("%lld\n", pre);
            // printf("%lld\n", post);
        }

        if (pre == post)
        {
            printf("YES\n");
        }

        else
        {
            printf("NO\n");
        }
    }
}


