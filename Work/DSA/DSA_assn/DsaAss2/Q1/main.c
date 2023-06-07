#include "functions.h"

int main()
{
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++)
    {
        Elementtype string[10002];
        scanf("%s", string);
        char *str;
        str = string;
        int chkbalanced;
        int chkpalindrome;
        chkbalanced = Balanced(str);

        int strilength = stringlen(str);
        chkpalindrome = Palindrome(str, strilength);

        if (chkpalindrome == 1)
        {
            printf("Palindromic\n");
        }

        else if (chkbalanced == 1)
        {
            printf("Balanced\n");
        }
        else
            printf("-1\n");
    }
}
