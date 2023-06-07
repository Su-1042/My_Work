#include "hash.h"

Hash CreateHash()
{
    Hash H;
    H = (Hash)malloc(sizeof(struct HashTable));
    assert(H != NULL);
    H->tablesize = 100003;
    H->pstart = (Ptr2structNode *)malloc(100003 * sizeof(Ptr2structNode));
    assert(H->pstart != NULL);
    for (int i = 0; i < 100003; i++)
    {
        H->pstart[i] = (Ptr2structNode)malloc(sizeof(struct node));
        // assert(H->pstart[i] != NULL);
        H->pstart[i]->pnext = NULL;
        H->pstart[i]->data = NULL;
    }
    return H;
}

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

int GetHashKey(char *c, Hash H)
{
    // each anangram has uniqueness to its operations
    int asciikey = 0;
    int strlength;
    int length = stringlen(c);

    for (int i = 0; i < length; i++)
    {
        asciikey += ((c[i] - 96) * (c[i] - 96) * (c[i] - 96));
        // asciikey = asciikey % 100003;
    }

    return (asciikey % 100003);
}

Ptr2structNode FindInHash(Hash H, char *element2find)
{
    Ptr2structNode Position = NULL;
    int hashkey;
    hashkey = GetHashKey(element2find, H);
    Position = H->pstart[hashkey]->pnext;
    while (Position != NULL)
    {
        if (strcmp(Position->data, element2find) == 0)
        {
            // printf("element already there\n");
            return Position;
        }

        Position = Position->pnext;
    }
    return Position;
}

void InsertInHash(Hash H, char *element2insert, Ptr2structNode *trackarray)
{
   

    Ptr2structNode newnode;
    // since the elemnt doesnt exit in the hashtable already so we will create space and insert the node that we wanted

        newnode = (Ptr2structNode)malloc(sizeof(struct node));

        int K;
        K = GetHashKey(element2insert, H);
        newnode->pnext = H->pstart[K]->pnext;
        newnode->data = element2insert;
        if (newnode->pnext == NULL)
        {

            H->pstart[K]->pnext = newnode;
        }
        else
        {
            trackarray[K]->pnext = newnode;
            newnode->pnext = NULL;
        }

        trackarray[K] = newnode;
        // newnode->pnext = H->pstart[K]->pnext;
        // newnode->data = element2insert;
        // H->pstart[K]->pnext = newnode;
    
}

int checkana(char *c1, char *c2)
{
    int stringlength1 = stringlen(c1);
    int stringlength2 = stringlen(c2);
    int check = 0;
    int checkarray[stringlength2];
    for (int k = 0; k < stringlength2; k++)
    {
        checkarray[k] = -1;
    }
    if (stringlength1 != stringlength2)
        return 0;

    for (int i = 0; i < stringlength1; i++)
    {
        for (int j = 0; j < stringlength2; j++)
        {
            if (c1[i] == c2[j] && checkarray[j] == -1)
            {
                checkarray[j] = -2;
                check++;
                break;
            }
        }
    }
    if (check == stringlength1)
        return 1;
    else
        return 0;
}

void PrintAnangrams(Hash H, char *AnaOf)
{
    int AnaKey;
    AnaKey = GetHashKey(AnaOf, H);
    // printf("i am here\n");
    int trackifwent = 0;
    // taking a dummy node to traverse each level
    Ptr2structNode track;
    track = H->pstart[AnaKey]->pnext;

    if (H->pstart[AnaKey]->pnext == NULL)
        printf("-1\n");

    else
    {
        while (track != NULL)
        {
            int flag = 0;
            
            flag = checkana(track->data, AnaOf);
            if (flag == 1)
            {
                printf("%s ", track->data);
                trackifwent = 1;
            }
            // printf("\n");
            track = track->pnext;
        }
        if (trackifwent==0)
        printf("-1\n");
        
        printf("\n");
    }
}
