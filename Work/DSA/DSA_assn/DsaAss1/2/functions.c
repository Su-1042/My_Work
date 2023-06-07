#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int *intersectionArray(int *arr1, int *arr2, int lenArr1, int lenArr2)
{
    int index = 0;
    int *alwaysfirstinarr2;
    alwaysfirstinarr2 = arr2;
    int *final;
    final = (int *)calloc(10000, sizeof(int));
    int *track1;
    track1 = (int *)calloc(10001, sizeof(int));
    int *track2;
    track2 = (int *)calloc(10001, sizeof(int));

    if (lenArr1 <= lenArr2)
    {

        for (int i = 0; i < lenArr2; i++)
        {
            track1[*arr2]++;

            if (i != (lenArr2 - 1))
                arr2++;
        }

        for (int m = 0; m < lenArr1; m++)
        {
            track2[*arr1]++;

            if (m != (lenArr1 - 1))

                arr1++;
        }
        // if shows an error try making the size as 10001
        for (int j = 0; j < 10001; j++)
        {
            if (track1[j] != 0 && track2[j] != 0)
            {
                if (track1[j] == track2[j])
                {
                    while (track1[j] != 0)
                    {
                        final[index] = j;
                        index++;
                        track1[j]--;
                    }
                }
                else if (track1[j] < track2[j])
                {
                    while (track1[j] != 0)
                    {
                        final[index] = j;
                        index++;
                        track1[j]--;
                    }
                }

                else if (track1[j] > track2[j])
                {
                    while (track2[j] != 0)
                    {
                        final[index] = j;
                        index++;
                        track2[j]--;
                    }
                }
            }
        }
    }

    else
    // if (lenArr1 > lenArr2)
    {
        for (int i = 0; i < lenArr1; i++)
        {
            track1[*arr1]++;

            if (i != (lenArr1 - 1))
                arr1++;
        }

        for (int m = 0; m < lenArr2; m++)
        {
            track2[*arr2]++;

            if (m != (lenArr2 - 1))

                arr2++;
        }

        arr2 = alwaysfirstinarr2;
        // if shows an error try making the size as 10001
        for (int j = 0; j < 10001; j++)
        {
            if (track1[j] != 0 && track2[j] != 0)
            {

                if (track1[j] == track2[j])
                {
                    while (track1[j] != 0)
                    {
                        final[index] = j;
                        index++;
                        track1[j]--;
                    }
                }
                else if (track1[j] < track2[j])
                {
                    while (track1[j] != 0)
                    {
                        final[index] = j;
                        index++;
                        track1[j]--;
                    }
                }

                else if (track1[j] > track2[j])
                {
                    while (track2[j] != 0)
                    {
                        final[index] = j;
                        index++;
                        track2[j]--;
                    }
                }
            }
        }
    }
    // free(track1);
    // free(track2);
    return final;
}

int countCharOccurrences(const char *str, int length, char ch)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {

        if (str[i] == ch)
        {
            count++;
        }
    }

    return count;
}

char *findLongestCommonPrefix(char **str, int numStr, int maxLen)
{
    char *final;
    final = (char *)malloc(101 * sizeof(char));
    int check;
    int flag = 0;
    for (int i = 0; i < maxLen; i++)
    {
        check = 0;

        for (int k = 0; k < numStr; k++)
        {
            if (str[0][i] == str[k][i])
            {
                check++;
            }

            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;

        if (check == numStr)
        {
            final[i] = str[0][i];
        }
    }
    return final;
}

char findFirstNonRepeatingChar(const char *str, int length)
{
    // if nothing words just make a san array of 26 elements and chk alphabet wise

    int flag;
    // int k = 0;
    char funny;

    for (int i = 0; i < length; i++)
    {
        flag = 0;
        for (int j = 0; j < length; j++)
        {
            if (i != j)
            {
                if (str[i] == str[j])
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
        {
            funny = str[i];
            return funny;
        }
    }
    if (flag == 1)
    {

        return '\0';
    }
}

int *maxMin(int *arr, int lenArr)
{
    int *finalarray;
    int *finalindexarri;
    int *finalindexarrd;
    finalindexarri = (int *)calloc(lenArr, sizeof(int));
    finalindexarrd = (int *)calloc(lenArr, sizeof(int));

    int max = -1;
    int indexi = 0;
    int indexd = 0;

    for (int i = 0; i < lenArr; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            finalindexarri[indexi] = i+1;
            indexi++;
        }
    }

    int min = 9999999;

    for (int i = (lenArr - 1); i >= 0; i--)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            finalindexarrd[indexd] = i+1;
            indexd++;
        }
    }

    // for (int i = 0; i < indexd; i++)
    // {
    //     printf("%d ", finalindexarrd[i]);
    // }
    // printf("\n");

    // for (int i = 0; i < indexi; i++)
    // {
    //     printf("%d ", finalindexarri[i]);
    // }
    // printf("\n");

    finalarray = intersectionArray(finalindexarri, finalindexarrd, (indexi), (indexd));

    return finalarray;
}


char *removeSubstring(char *str, int strlength, const char *substr, int substrlength)
{

    int index;
    int finalindex = 0;
    int i = 0;
    int flag;
    char *final;
    final = (char *)malloc(1000000 * sizeof(char));
    final[0] = '\0';

    while (i <=strlength)
    {
        flag = 0;
        index = 0;
        if (str[i] == substr[index])
        {
            int temp = i;
            int check = 1;

            while (index < substrlength && temp < strlength-1)
            {
                index++;
                temp++;
                if (str[temp] == substr[index])
                {
                    check++;
                }
                else
                {
                    break;
                }
            }
            //printf(" check %d\n",check);
            if (check == substrlength)
            {
                 i = i + substrlength;
                // printf("REMOVED\n");
            }
            else
            {   
                final[finalindex] = str[i];
                //printf("%c\n",final[finalindex]);
                i++;
                //printf("%d\n",finalindex);
                finalindex++;
               // printf("%s\n",final);

            }
        }
        else
        {

            final[finalindex] = str[i];
           // printf("%c\n",final[finalindex]);
            i++;
            finalindex++;
        }
    }

    return final;
}
