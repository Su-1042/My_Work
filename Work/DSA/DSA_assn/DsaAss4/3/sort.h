#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>

struct bisleri
{
    int stringlength;
    char *c;
};

typedef struct bisleri *word;

int stringlen(char *string);
int comparestrings(struct bisleri s1, struct bisleri s2);
void printdict(int n, word words);
void Merge(word arr, int lower, int mid, int upper);
void MSDriver(word arr, int lower, int upper);
void MergeWords(word arr, int n);

#endif