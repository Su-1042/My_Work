#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// in the queue we see that the
//  the necessary things are the
//  pointer to front,rear,capacity,count of elements ay onve

typedef struct que *Que;
typedef int elementType;

struct que
{
    int capacity;
    int front;
    int rear;
    int count;
    elementType *arrayeletype;
};

Que quinit(maxelem)
{
    Que Q;
    Q = (Que)malloc(sizeof(struct que));
    Q->arrayeletype = (int *)malloc(maxelem * sizeof(int));
    Q->front = 0;
    Q->rear = -1;
    Q->count = 0;
}

int IsFull(Que Q)
{
    return (Q->count == Q->capacity);
}

int IsEmpty(Que Q)
{
    return (Q->count == 0);
}

void Enque(Que Q, elementType e)
{
    if (IsFull(Q))
    {
        printf("queue is already full\n");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1) % (Q->capacity);
        Q->arrayeletype[Q->rear] = e;
        Q->count++;
    }
}

elementType Deque(Que Q)
{
    elementType e;
    if (IsEmpty)
    {
        printf("queue is already empty\n");
    }
    else
    {
        e = Q->arrayeletype[Q->front];
        Q->front = (Q->front + 1) % (Q->capacity);
        return e;
    }
}

void printqueue(Que Q)
{
    int temp = Q->front;
    while (Q->rear == temp)
    {
        printf("%d", Q->arrayeletype[temp]);
        temp = (temp + 1) % (Q->capacity);
    }
}















