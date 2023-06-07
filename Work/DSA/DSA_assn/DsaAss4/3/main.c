#include "sort.h"

int main()
{
    int testcases;
    scanf("%d", &testcases);

    for (int t = 0; t < testcases; t++)
    {
        int numwords;
        scanf("%d", &numwords);

        word words;
        words = (word)malloc(sizeof(struct bisleri) * numwords);

        for (int i = 0; i < numwords; i++)
        {
            scanf("%d", &words[i].stringlength);

            words[i].c = (char *)malloc(sizeof(char) * (words[i].stringlength+3));
            scanf("%s", words[i].c);
        }

        MergeWords(words,numwords);
    }
}