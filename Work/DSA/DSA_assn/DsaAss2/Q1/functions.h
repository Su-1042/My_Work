#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stack *Stack;
typedef char Elementtype;

struct stack
{
    int top;
    int maxelements;
    Elementtype *ptr2topofstack;
};

int stringlen(char* string);

int Palindrome(char *str, int strlen);

int Balanced(char *str);

Elementtype Top(const Stack S);

void Push(Stack S, Elementtype e);

int Pop(Stack S);

int IsEmpty(Stack S);

Stack stackinit();

#endif