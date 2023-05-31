#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double Elementtype;

struct stack
{
    long int top;
    Elementtype Maxelements;
    Elementtype *ptr2topofstack;
};

typedef struct stack *Stack;

void Push(Stack S, Elementtype e);
Elementtype Pop(Stack S);
Elementtype Top(const Stack S);

// we pass const stack as we dont want the actual stack to change when we pass in the

Stack Stackinitialise(Elementtype max_elements)
{

    Stack S;
    S = (Stack)malloc(max_elements * sizeof(struct stack *));
    assert(S != NULL);
    S->ptr2topofstack = (Elementtype *)malloc(sizeof(Elementtype *));
    S->top = -1;
    S->Maxelements = max_elements;
    return S;
}

int IsEmpty(Stack S)
{
    return (S->top==-1);
}


int IsFull(Stack S)
{
    if (S->top==(S->Maxelements -1))
    {
        return 0;
    }
    else 
    return 1;
}

Elementtype Pop(Stack S)
{
    if (!IsEmpty(S))
    {
        Elementtype e = S->ptr2topofstack[S->top];
        --S->top;
        return e;
    }

    else
    {
        printf("the stack is empty and nothing can be pooped\n");
    }
}

void Push(Stack S, Elementtype e)
{
    if (IsFull(S))
    {
        S->ptr2topofstack[++S->top]=e;
    }

    else 
    printf("the stack is already full\n");
}

Elementtype Top(const Stack S){
    return S->ptr2topofstack[S->top];
}

// void prinstack(){

// }





int main(){

    printf("enter the maximum number of elements in the satck\n");
    Elementtype max_elements;
    //what is the format specifier of Elementtype
    scanf("%lf",&max_elements);
    Stack Sup;
    Sup = Stackinitialise(max_elements);
    int uwant;
    printf("enter the number of opertaions that u want to perform\n");
    scanf("%d",&uwant);

    for (int i=0;i<uwant;i++)
    {
        char operationname[10];
        scanf("%s",operationname);

        if (operationname[1]=='u')
        {
            Elementtype e;
            scanf("%lf",&e);
            Push (Sup,e);
        }

        else if (operationname=="pop")
        {

            Pop(Sup);
        }

        else if (operationname=="top")
        {
            Elementtype e;
            e= Top(Sup);
            printf("%lf",e);
        }

        // else 
        // {
        //     printstack(Sup);
        // }

    }
    
}