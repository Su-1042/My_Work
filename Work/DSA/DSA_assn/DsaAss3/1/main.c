#include "hash.h"

int main()
{
    int stringnum;
    int querienum;
    Hash H;

    H = CreateHash();
    scanf("%d", &stringnum);
    scanf("%d", &querienum);
    char **strings;
    strings = (char **)malloc(stringnum * sizeof(char *));
    char **query;
    query = (char **)malloc(querienum * sizeof(char *));

    Ptr2structNode *trackarray;
    trackarray = (Ptr2structNode *)malloc(sizeof(Ptr2structNode));
    for (int i = 0; i < 100003; i++)
    {
        trackarray[i] = (Ptr2structNode)malloc(sizeof(struct node));
    }
    for (int i = 0; i < stringnum; i++)
    {

        strings[i] = (char *)malloc(11 * sizeof(char));
        scanf("%s", strings[i]);
        InsertInHash(H, strings[i], trackarray);
        // printf("%s is inserted\n", strings[i]);
    }

    for (int i = 0; i < querienum; i++)
    {
        query[i] = (char *)malloc(11 * sizeof(char));
        scanf("%s", query[i]);
        PrintAnangrams(H, query[i]);
    }
}




