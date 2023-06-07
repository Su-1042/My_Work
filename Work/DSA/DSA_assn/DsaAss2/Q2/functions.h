#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct node *Node;
typedef Node *Queue;

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

Node CreateNode(int val);
void Push(Queue head, int val);
int Pop(Queue head);
void Inject(Queue head, int val);
int popRear(Queue head);
void Print(Queue head);
void PrintReverse(Queue head);
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);

extern Node rear;

#endif 



