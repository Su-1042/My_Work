#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct HashTable *Hash;
typedef struct node *Ptr2structNode;

struct HashTable
{
    int tablesize;
    Ptr2structNode *pstart;
};

struct node
{
    char *data;
    Ptr2structNode pnext;
};

Hash CreateHash();
int stringlen(char *string);
int GetHashKey(char *c, Hash H);

Ptr2structNode FindInHash(Hash H, char *element2find);
void InsertInHash(Hash H, char *element2insert, Ptr2structNode *trackarray);
int checkana(char *c1, char *c2);
void PrintAnangrams(Hash H, char *AnaOf);


#endif