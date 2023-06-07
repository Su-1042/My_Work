#include <stdio.h>
#include <stdlib.h>
typedef struct node *Ptrnode;



struct node
{
    int Element;
    struct node *next;
};


void insert(int num);

Ptrnode Find(int num );

void print( );

extern Ptrnode head;
extern Ptrnode tempalwaystolastelement;
