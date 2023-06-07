#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define int long long  
int *Power(int num, int stringlength);
int *PrefixArray(const char *c, int stringlength, int *powerarray);
int *SuffixArray(char *c, int stringlength, int *powerarray);

extern int mod;

#endif