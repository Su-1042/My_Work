#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

// debug 3 and 6

int main()
{
    int number_of_operations2BPErformed;
    scanf("%d", &number_of_operations2BPErformed);

    for (int i = 0; i < number_of_operations2BPErformed; i++)
    {
        char operationname[20];

        scanf("%s", operationname);

        if (operationname[4] == '1')
        {
            int length1;
            int length2;
            scanf("%d", &length1);
            scanf("%d", &length2);
            int *arr1;
            int *arr2;
            arr1 = (int *)malloc(length1 * sizeof(int));
            arr2 = (int *)malloc(length2 * sizeof(int));

            for (int i = 0; i < length1; i++)
            {
                scanf("%d", &arr1[i]);
            }
            for (int i = 0; i < length2; i++)
            {
                scanf("%d", &arr2[i]);
            }

            int *final;
            final = intersectionArray(arr1, arr2, length1, length2);
            int flag = 0;

            // either sort the final array which is a tedious tak or sort the smaller of the two arrays

            int lengthoffinal = 0;
            for (int i = 0; i < 10000; i++)
            {
                if (final[i] != 0)
                {
                    lengthoffinal++;
                }
                else
                    break;
            }

            // for (int i=0;i<lengthoffinal;i++){
            //     for (int j=0;j<lengthoffinal;j++){
            //         if (final[i]>final[j]){
            //             int temp=final[i];
            //             final[i]=final[j];
            //             final[j]=final[i];

            //         }
            //     }
            // }

            if (length1 <= length2)
            {
                for (int i = 0; i < lengthoffinal; i++)
                {
                    if (final[i] != 0)
                    {
                        flag = 1;
                        printf("%d ", final[i]);
                    }
                }
            }

            else
            {
                for (int i = 0; i < lengthoffinal; i++)
                {
                    if (final[i] != 0)
                    {
                        flag = 1;
                        printf("%d ", final[i]);
                    }
                }
            }

            if (flag == 0)
            {
                printf("-1\n");
            }

            else
                printf("\n");

            free(final);
        }

        else if (operationname[4] == '2')
        {
            int stringlength;
            scanf("%d", &stringlength);
            char *str;
            str = (char *)malloc((stringlength + 1) * sizeof(char));
            scanf("%s", str);
            const char *string;
            string = str;
            char buffer;
            scanf("%c", &buffer);
            char ch;
            scanf("%c", &ch);
            int count;
            count = countCharOccurrences(str, stringlength, ch);
            printf("%d\n", count);
        }

        else if (operationname[4] == '3')
        {
            int stringlength;
            scanf("%d", &stringlength);
            char *str;
            str = (char *)malloc((stringlength + 1) * sizeof(char));
            scanf("%s", str);
            const char *string;
            string = str;
            char fnr;
            fnr = findFirstNonRepeatingChar(str, stringlength);

            if (fnr == '\0')
            {
                printf("-1\n");
            }
            else
                printf("%c\n", fnr);
        }

        else if (operationname[4] == '4')
        {

            int numberofstrings;
            scanf("%d", &numberofstrings);
            char **string;
            string = (char **)malloc(numberofstrings * sizeof(char *));
            for (int j = 0; j < numberofstrings; j++)
            {
                string[j] = (char *)malloc(101 * sizeof(char));
            }
            int max = 0;
            for (int i = 0; i < numberofstrings; i++)
            {
                int stringlength;
                if (stringlength >= max)
                {
                    max = stringlength;
                }
                scanf("%d", &stringlength);
                scanf("%s", string[i]);
            }
            char *final;
            final = findLongestCommonPrefix(string, numberofstrings, max);

            if (final[0] == '\0')
            {
                printf("-1\n");
            }

            else
                printf("%s\n", final);

            string = (char **)malloc(numberofstrings * sizeof(char *));
            for (int j = 0; j < numberofstrings; j++)
            {
                free(string[j]);
            }
            free(string);

            free(final);
        }

        else if (operationname[4] == '5')
        {

            int arraysize;
            scanf("%d", &arraysize);
            int *arr;
            arr = (int *)malloc((arraysize+1)* sizeof(int));

            for (int i = 0; i < arraysize; i++)
            {
                scanf("%d", &arr[i]);
            }

            int *finalarray = maxMin(arr, arraysize);

            if (finalarray[0] == 0)
                printf("-1\n");

            else
            {
                for (int i = 0; i < arraysize; i++)
                {
                    if (finalarray[i] != 0)
                    printf("%d ", finalarray[i] - 1);
                }
                printf("\n");
            }
       
        }

        else if (operationname[4] == '6')
        {
            int stringlength;
            int substrlength;
            scanf("%d", &stringlength);
            scanf("%d", &substrlength);

            char *ptr2str;
            char *substr;
            ptr2str = (char *)malloc((stringlength + 1) * sizeof(char));
            substr = (char *)malloc((substrlength + 1) * sizeof(char));
            scanf("%s",ptr2str);
            scanf("%s",substr);

            const char *ptr2substr=substr;
            char *ptrfinalmodifiedstr;
            ptrfinalmodifiedstr = removeSubstring(ptr2str, stringlength, ptr2substr, substrlength);

            if (ptrfinalmodifiedstr[0] == '\0')
                printf("-1\n");

            else
            {
                printf("%s\n", ptrfinalmodifiedstr);
            }

            free(ptr2str);
            free(substr);
            free(ptrfinalmodifiedstr);
        }
    }
}